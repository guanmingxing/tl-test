import "DPI-C" function chandle create_interface();
import "DPI-C" function chandle create_CAgent(chandle intf);
import "DPI-C" function void get_channelD_signal(
                                input chandle intf_a,
                                output bit [2:0]    opcode,
                                output bit [2:0]    param,
                                output bit [2:0]    size,
                                output bit [6:0]    source,
                                output bit [3:0]    sink,
                                output bit          denied,
                                output bit [255:0]  data,
                                output bit          corrupt,
                                output bit          dirty
                            );
import "DPI-C" function void CAgent_do_grantData(
                            input chandle agt,
                            input int     address,
                            input int     param,
                            input int     size,
                            input int     source,
                            input bit[255:0]     data,
                            input int     dirty
                        );
import "DPI-C" function void CAgent_update_signal(chandle agt);