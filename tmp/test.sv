import "DPI-C" function chandle create_CModel();
import "DPI-C" function void    do_probe(chandle *agt);

import "DPI-C" function void get_signal_from_slave_b (
    output bit  [2:0] opcode,
    output bit  [2:0] param,
    output bit  [2:0] size,
    output bit  [6:0] source,
    output bit  [35:0] address,
    output bit  [31:0] mask,
    output bit  [255:0] data,
    output bit  corrupt,
    chandle   agt );

module test;
    bit  [2:0] opcode;
    bit  [2:0] param;
    bit  [2:0] size;
    bit  [6:0] source;
    bit  [35:0] address;
    bit  [31:0] mask;
    bit  [255:0] data;
    bit         corrupt;
    initial begin
        
        chandle agt = create_CModel();
        do_probe(agt);
        get_signal_from_slave_b(
            opcode,
            param,
            size,
            source,
            address,
            mask,
            data,
            corrupt,
            agt
        );
    end
endmodule