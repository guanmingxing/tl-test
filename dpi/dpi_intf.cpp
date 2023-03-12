#include "svdpi.h"

#include "../Interface/interface.h"
#include "../TLAgent_Slave/CAgent.h"
#include "../TLAgent_Slave/CAgent.cpp"

using namespace tl_agent;
using namespace tl_interface;

#ifdef __cplusplus
extern "C" {
#endif

void* create_interface() {
    interface *intf = new interface();
    return (void*)intf;
}

void* create_CAgent(void *intf_a) {
    interface *intf = (interface*)intf_a;
    CAgent *cagt = new CAgent(3, intf);
    return (void*)cagt;
}

void get_channelD_signal(
    void            *intf_a,
    svBitVecVal     *opcode,
    svBitVecVal     *param,
    svBitVecVal     *size,
    svBitVecVal     *source,
    svBitVecVal     *sink,
    svBitVecVal     *denied,
    svBitVecVal     *data,
    svBit           *corrupt,
    svBit           *dirty
) {
    interface *intf = (interface *)intf_a;
    //uint8_t *data_tmp = new uint8_t[8];
    //memcpy(data_tmp, data, 8);
    intf->chnD->tlc_agent_eval_channelD(
        opcode,
        param,
        size,
        source,
        sink,
        denied,
        data,
        corrupt,
        dirty
    );
}

void CAgent_do_grantData(
    const void *agt,
    const int address,
    const int param,
    const int size,
    const int source,
    const svBitVecVal *data,
    const int dirty
) {
    CAgent *cagt = (CAgent*)agt;
    uint8_t *data_tmp = new uint8_t[DATASIZE];
    memcpy(data_tmp, data, DATASIZE);
    cagt->do_grantData(
        address,
        param,
        size,
        source,
        data_tmp,
        dirty
    );
}

void CAgent_update_signal(void *agt) {
    CAgent *cagt = (CAgent*)agt;
    cagt->update_signal();
}

#ifdef __cplusplus
}
#endif