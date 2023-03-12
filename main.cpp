#include "./dpi/dpi_intf.cpp"
using namespace tl_agent;
using namespace tl_interface;
int main() {
    void *intf = create_interface();
    void *agt = create_CAgent(intf);
    svBitVecVal* data = new uint32_t[DATASIZE/4];
    CAgent_do_grantData(agt, 1, 2, 3, 4, data, 1);
    CAgent_update_signal(agt);
    return 0;
}