#include "./TLAgent_Slave/CAgent.cpp"
#include "./Utils/ScoreBoard.h"

using namespace tl_agent;

#ifdef __cplusplus
extern "C" {
#endif

void* create_CModel() {
    GlobalBoard<paddr_t> *gb = new GlobalBoard<paddr_t>();
    CAgent *agt = new CAgent(gb, 11);
    return (void *)agt;
}

void do_grantData(void *agt) {
    uint8_t data[100] = {12};
    CAgent *cagt = (CAgent *)agt;
    cagt->do_grantData(123, 1, 2, 111, (uint8_t*)data, 0);
}

void do_probe(void *agt) {
    CAgent *cagt = (CAgent *)agt;
    cagt->do_probe();
}

void get_signal_from_slave_b (
    svLogicVecVal*  opcode,
    svLogicVecVal*  param,
    svLogicVecVal*  size,
    svLogicVecVal*  source,
    svLogicVecVal*  address,
    svLogicVecVal*  mask,
    svLogicVecVal*  data,
    svLogic*        corrupt,
    void            *agt
) {
    CAgent *cagt = (CAgent *)agt;
    cagt->get_signal_from_slave_b(
        opcode,
        param,
        size,
        source,
        address,
        mask,
        data,
        corrupt
    );
}

#ifdef __cplusplus
}
#endif

// int main() {
//     void *agt = create_CModel();
//     do_grantData(agt);
//     return 0;
// }