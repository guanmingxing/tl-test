`include "./dpi/dpi_intf.sv"
module test;
    bit [2:0]    opcode;
    bit [2:0]    param;
    bit [2:0]    size;
    bit [6:0]    source;
    bit [3:0]    sink;
    bit          denied;
    bit [255:0]  data;
    bit          corrupt;
    bit          dirty;

    initial begin
        bit [255:0] data_tmp = 256'hfffffffffff;
        chandle intf = create_interface();
        chandle agt = create_CAgent(intf);
        CAgent_do_grantData(agt, 1, 2, 3, 4, data_tmp, 0);
        $display("------1");
        CAgent_update_signal(agt);
        $display("sssss2");
        #10;
        get_channelD_signal(intf, opcode, param, size, source, sink, denied, data, corrupt, dirty);
        $display(data);
        $display(opcode);
        $display(param);
        $display(sink);
    end
endmodule