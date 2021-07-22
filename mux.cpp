#include "systemc.h"
#include "mux.h"

SC_HAS_PROCESS(mux);

// constructor
mux::mux(sc_module_name name) : sc_module(name)
{
    SC_METHOD(muxProcess);
    sensitive << in1 << in2 << select;
}

void mux::muxProcess()
{
    out.write(select ? in1 : in2);
}
