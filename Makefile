run:
	vcs -full64 -sverilog -kdb -lca -debug_access+all -CFLAGS -std=c++11 ./test.sv ./dpi/dpi_intf.cpp