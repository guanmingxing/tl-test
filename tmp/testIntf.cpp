#include "./Interface/interface.h"

//using namespace tl_interface;

#ifdef __cplusplus
extern "C" {
#endif

void* create_CModel() {
    interface *intf = new interface();
    return (void *)intf;
}

void test(
    input void *intf,
    svBitVecVal*  opcode,
    svBitVecVal*  param,
    svBitVecVal*  size,
    svBitVecVal*  source,
    svBitVecVal*  address,
    svBitVecVal*  mask,
    svBitVecVal*  data,
    svBit*        corrupt,
    svBit*          valid
) {
    uint8_t data[32] = {1, 2, 3,4,5,6,7,8,9};
    intf.channelb.signal_update(
        0,1,2,3,4,5,6,7,data
    );
    intf.channelb.tlc_agent_eval_channelB(
        opcode,
        param,
        size,
        source,
        address,
        mask,
        data,
        corrupt,
        valid
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