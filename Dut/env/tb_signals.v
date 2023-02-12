  wire          s_dma_aw_ready,
  wire          s_dma_aw_valid,
  wire  [13:0]  s_dma_aw_id,
  wire  [35:0]  s_dma_aw_addr,
  wire  [7:0]   s_dma_aw_len,
  wire  [2:0]   s_dma_aw_size,
  wire  [1:0]   s_dma_aw_burst,
  wire          s_dma_aw_lock,
  wire  [3:0]   s_dma_aw_cache,
  wire  [2:0]   s_dma_aw_prot,
  wire  [3:0]   s_dma_aw_qos,
  wire          s_dma_w_ready,
  wire          s_dma_w_valid,
  wire  [255:0] s_dma_w_data,
  wire  [31:0]  s_dma_w_strb,
  wire          s_dma_w_last,
  wire          s_dma_b_ready,
  wire          s_dma_b_valid,
  wire  [13:0]  s_dma_b_id,
  wire  [1:0]   s_dma_b_resp,
  wire          s_dma_ar_ready,
  wire          s_dma_ar_valid,
  wire  [13:0]  s_dma_ar_id,
  wire  [35:0]  s_dma_ar_addr,
  wire  [7:0]   s_dma_ar_len,
  wire  [2:0]   s_dma_ar_size,
  wire  [1:0]   s_dma_ar_burst,
  wire          s_dma_ar_lock,
  wire  [3:0]   s_dma_ar_cache,
  wire  [2:0]   s_dma_ar_prot,
  wire  [3:0]   s_dma_ar_qos,
  wire          s_dma_r_ready,
  wire          s_dma_r_valid,
  wire  [13:0]  s_dma_r_id,
  wire  [255:0] s_dma_r_data,
  wire  [1:0]   s_dma_r_resp,
  wire          s_dma_r_last,
  wire          m_peripheral_aw_ready,
  wire          m_peripheral_aw_valid,
  wire  [1:0]   m_peripheral_aw_id,
  wire  [30:0]  m_peripheral_aw_addr,
  wire  [7:0]   m_peripheral_aw_len,
  wire  [2:0]   m_peripheral_aw_size,
  wire  [1:0]   m_peripheral_aw_burst,
  wire          m_peripheral_aw_lock,
  wire  [3:0]   m_peripheral_aw_cache,
  wire  [2:0]   m_peripheral_aw_prot,
  wire  [3:0]   m_peripheral_aw_qos,
  wire          m_peripheral_w_ready,
  wire          m_peripheral_w_valid,
  wire  [63:0]  m_peripheral_w_data,
  wire  [7:0]   m_peripheral_w_strb,
  wire          m_peripheral_w_last,
  wire          m_peripheral_b_ready,
  wire          m_peripheral_b_valid,
  wire  [1:0]   m_peripheral_b_id,
  wire  [1:0]   m_peripheral_b_resp,
  wire          m_peripheral_ar_ready,
  wire          m_peripheral_ar_valid,
  wire  [1:0]   m_peripheral_ar_id,
  wire  [30:0]  m_peripheral_ar_addr,
  wire  [7:0]   m_peripheral_ar_len,
  wire  [2:0]   m_peripheral_ar_size,
  wire  [1:0]   m_peripheral_ar_burst,
  wire          m_peripheral_ar_lock,
  wire  [3:0]   m_peripheral_ar_cache,
  wire  [2:0]   m_peripheral_ar_prot,
  wire  [3:0]   m_peripheral_ar_qos,
  wire          m_peripheral_r_ready,
  wire          m_peripheral_r_valid,
  wire  [1:0]   m_peripheral_r_id,
  wire  [63:0]  m_peripheral_r_data,
  wire  [1:0]   m_peripheral_r_resp,
  wire          m_peripheral_r_last,
  wire          m_memory_aw_ready,
  wire          m_memory_aw_valid,
  wire  [13:0]  m_memory_aw_id,
  wire  [35:0]  m_memory_aw_addr,
  wire  [7:0]   m_memory_aw_len,
  wire  [2:0]   m_memory_aw_size,
  wire  [1:0]   m_memory_aw_burst,
  wire          m_memory_aw_lock,
  wire  [3:0]   m_memory_aw_cache,
  wire  [2:0]   m_memory_aw_prot,
  wire  [3:0]   m_memory_aw_qos,
  wire          m_memory_w_ready,
  wire          m_memory_w_valid,
  wire  [255:0] m_memory_w_data,
  wire  [31:0]  m_memory_w_strb,
  wire          m_memory_w_last,
  wire          m_memory_b_ready,
  wire          m_memory_b_valid,
  wire  [13:0]  m_memory_b_id,
  wire  [1:0]   m_memory_b_resp,
  wire          m_memory_ar_ready,
  wire          m_memory_ar_valid,
  wire  [13:0]  m_memory_ar_id,
  wire  [35:0]  m_memory_ar_addr,
  wire  [7:0]   m_memory_ar_len,
  wire  [2:0]   m_memory_ar_size,
  wire  [1:0]   m_memory_ar_burst,
  wire          m_memory_ar_lock,
  wire  [3:0]   m_memory_ar_cache,
  wire  [2:0]   m_memory_ar_prot,
  wire  [3:0]   m_memory_ar_qos,
  wire          m_memory_r_ready,
  wire          m_memory_r_valid,
  wire  [13:0]  m_memory_r_id,
  wire  [255:0] m_memory_r_data,
  wire  [1:0]   m_memory_r_resp,
  wire          m_memory_r_last,
  wire          io_clock,
  wire          io_reset,
  wire  [63:0]  io_extIntrs,
  wire          io_systemjtag_jtag_TCK,
  wire          io_systemjtag_jtag_TMS,
  wire          io_systemjtag_jtag_TDI,
  wire          io_systemjtag_jtag_TDO_data,
  wire          io_systemjtag_jtag_TDO_driven,
  wire          io_systemjtag_reset,
  wire  [10:0]  io_systemjtag_mfr_id,
  wire  [15:0]  io_systemjtag_part_number,
  wire  [3:0]   io_systemjtag_version,
  wire          io_debug_reset,
  wire          io_riscv_halt_0,
  wire          io_riscv_halt_1,
  wire          scan_mode,
  wire          dft_lgc_rst_n,
  wire          dft_mode,
  wire          dft_ram_hold,
  wire          dft_ram_bypass,
  wire          dft_ram_bp_clken,
  wire          dft_l3dataram_clk,
  wire          dft_l3dataramclk_bypass,
  wire          dft_cgen;

  assign s_dma_aw_valid = 0;
  assign s_dma_aw_id = 0;
  assign s_dma_aw_addr = 0;
  assign s_dma_aw_len = 0;
  assign s_dma_aw_size = 0;
  assign s_dma_aw_burst = 0;
  assign s_dma_aw_lock = 0;
  assign s_dma_aw_cache = 0;
  assign s_dma_aw_prot = 0;
  assign s_dma_aw_qos = 0;
  assign s_dma_w_valid = 0;
  assign s_dma_w_data = 0;
  assign s_dma_w_strb = 0;
  assign s_dma_w_last = 0;
  assign s_dma_b_ready = 0;
  assign s_dma_ar_valid = 0;
  assign s_dma_ar_id = 0;
  assign s_dma_ar_addr = 0;
  assign s_dma_ar_len = 0;
  assign s_dma_ar_size = 0;
  assign s_dma_ar_burst = 0;
  assign s_dma_ar_lock = 0;
  assign s_dma_ar_cache = 0;
  assign s_dma_ar_prot = 0;
  assign s_dma_ar_qos = 0;
  assign s_dma_r_ready = 0;
  assign m_peripheral_aw_ready = 0;
  assign m_peripheral_w_ready = 0;
  assign m_peripheral_b_valid = 0;
  assign m_peripheral_b_id = 0;
  assign m_peripheral_b_resp = 0;
  assign m_peripheral_ar_ready = 0;
  assign m_peripheral_r_valid = 0;
  assign m_peripheral_r_id = 0;
  assign m_peripheral_r_data = 0;
  assign m_peripheral_r_resp = 0;
  assign m_peripheral_r_last = 0;
  assign io_extIntrs = 0;
  assign io_systemjtag_jtag_TCK = 0;
  assign io_systemjtag_jtag_TMS = 0;
  assign io_systemjtag_jtag_TDI = 0;
  assign io_systemjtag_reset = 0;
  assign io_systemjtag_mfr_id = 0;
  assign io_systemjtag_part_number = 0;
  assign io_systemjtag_version = 0;
  assign scan_mode = 0;
  assign dft_lgc_rst_n = 0;
  assign dft_mode = 0;
  assign dft_ram_hold = 0;
  assign dft_ram_bypass = 0;
  assign dft_ram_bp_clken = 0;
  assign dft_l3dataram_clk = 0;
  assign dft_l3dataramclk_bypass = 0;
  assign dft_cgen = 0;








