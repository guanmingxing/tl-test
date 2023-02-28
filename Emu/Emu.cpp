//
// Created by ljw on 10/22/21.
//

#include "Emu.h"

uint64_t Cycles;
bool Verbose = false;

double sc_time_stamp() { return 0; }

void Emu::parse_args(int argc, char **argv) {
  const struct option long_options[] = {{"seed", 1, NULL, 's'},
                                        {"wave-begin", 1, NULL, 'b'},
                                        {"wave-end", 1, NULL, 'e'},
                                        {"cycles", 1, NULL, 'c'},
                                        {"verbose", 0, NULL, 'v'},
                                        {"fullwave", 0, NULL, 'f'},
                                        {"monitor", 0, NULL, 'm'},
                                        {"random", 0, NULL, 'r'},
                                        {0, 0, NULL, 0}};
  int o;
  int long_index = 0;
  while ((o = getopt_long(argc, const_cast<char *const *>(argv), "-s:b:e:c:mvfr",
                          long_options, &long_index)) != -1) {
    switch (o) {
    case 's':
      this->seed = atoll(optarg);
      break;
    case 'b':
      this->wave_begin = atoll(optarg);
      break;
    case 'e':
      this->wave_end = atoll(optarg);
      break;
    case 'c':
      this->exe_cycles = atoll(optarg);
      break;
    case 'v':
      Verbose = true;
      break;
    case 'm':
      en_monitor = true;
      break;
    case 'f':
      all_wave = true;
      break;
    case 'r':
      random_mode = false;
      break;
    default:
      tlc_assert(false, "Unknown args!");
    }
  }
  if(all_wave){
    this->wave_begin = 0;
    this->wave_end = this->exe_cycles;
  }
  if ((this->wave_begin >= this->wave_end)) {
    this->enable_wave = false;
  }
}

Emu::Emu(int argc, char **argv) {
  this->parse_args(argc, argv);
  Verilated::commandArgs(argc, argv);
  Cycles = 0;
  dut_ptr = new Vtb_top();
  globalBoard = new GlobalBoard<paddr_t>(); // address indexed

  printf("[INFO] use seed: %ld\n", this->seed);
  srand(this->seed);

  // Init agents
  for (int i = 0; i < NR_CAGENTS; i++) {
    agents[i].reset(new CAgent_t(globalBoard, i, &Cycles, i / 2, i % 2));
    fuzzers[i].reset(new CFuzzer(std::dynamic_pointer_cast<tl_agent::CAgent>(agents[i])));
    fuzzers[i]->set_cycles(&Cycles); 
  }

  for (int i = NR_CAGENTS; i < NR_CAGENTS + NR_PTWAGT; i++) {
    agents[i].reset(new ULAgent_t(globalBoard, i, &Cycles, i % 2, PTW_BUS_TYPE));
    fuzzers[i].reset(new ULFuzzer(std::dynamic_pointer_cast<tl_agent::ULAgent>(agents[i])));
    fuzzers[i]->set_cycles(&Cycles);
  }

  for (int i = NR_CAGENTS + NR_PTWAGT; i < NR_AGENTS; i++) {
    agents[i].reset(new ULAgent_t(globalBoard, i, &Cycles, 0xffffffffffffffffL, DMA_BUS_TYPE));
    fuzzers[i].reset(new ULFuzzer(std::dynamic_pointer_cast<tl_agent::ULAgent>(agents[i])));
    fuzzers[i]->set_cycles(&Cycles);
  }

  if (random_mode == false)
  {
    for (int i = 0; i < NR_AGENTS; i++)
    {
      fuzzers[i]->init_testcase();//Input file test.txt
    }
  }
  

  if(this->en_monitor){
    for (int i = 0; i < NR_TILE_MONITOR; i++) {
      monitors[i].reset(new tl_monitor::Monitor(&Cycles, i, TILE_BUS_TYPE));
    }

    for (int i = NR_TILE_MONITOR; i < NR_TILE_MONITOR + NR_L3_MONITOR; i++) {
      monitors[i].reset(new tl_monitor::Monitor(&Cycles, i - NR_TILE_MONITOR, L3_BUS_TYPE));
    }

    for (int i = NR_TILE_MONITOR + NR_L3_MONITOR; i < NR_TL_MONITOR; i++) {
      monitors[i].reset(new tl_monitor::Monitor(&Cycles, i - NR_TILE_MONITOR - NR_L3_MONITOR, DMA_BUS_TYPE));
    }

    for (int i = 0; i < NR_DIR_MONITOR; i++) {
      dir_monitors[i].reset(new tl_monitor::DIR_Monitor(&Cycles, i, DIR_BUS_TYPE));
    }
  }
#if VM_TRACE == 1
  if (this->enable_wave) {
    Verilated::traceEverOn(true); // Verilator must compute traced signals
    tfp = new VerilatedVcdC;
    dut_ptr->trace(tfp, 99); // Trace 99 levels of hierarchy
    time_t now = time(NULL);
    tfp->open(cycle_wavefile(Cycles, now));
  }
#endif
}

Emu::~Emu() {
  delete dut_ptr;
#if VM_TRACE == 1
  if (this->enable_wave) {
    this->tfp->close();
  }
#endif
}

//reset_sys
void Emu::reset_sys(uint64_t n){
    reset(n);
    this->globalBoard->clear();
    for (size_t i = 0; i < NR_AGENTS; i++)
    {
      agents[i]->clear();
    }
}

void Emu::execute(uint64_t nr_cycle) {
  while (Cycles < nr_cycle) {
    if(this->en_monitor){
      for(int i = 0; i < NR_TL_MONITOR; i++){
        monitors[i]->print_info();
      }
      for(int i = 0; i < NR_DIR_MONITOR; i++){
        dir_monitors[i]->print_info();
      }
    }

    if(fuzzers[0]->do_reset(Cycles)){//reset message store in agent 0
      reset_sys(10);
    }

    for (int i = 0; i < NR_AGENTS; i++) {
      agents[i]->handle_channel();
    }

    for (int i = 0; i < NR_AGENTS; i++) {
      fuzzers[i]->tick(agents, i, random_mode);
    }

    for (int i = 0; i < NR_AGENTS; i++) {
      agents[i]->update_signal();
    }

    this->step();
    this->update_cycles(1);
  }
}
