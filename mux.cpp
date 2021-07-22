#include "systemc.h"
#include "mux.h"


// constructor
SC_HAS_PROCESS(mux);

mux::mux(sc_module_name name) : sc_module(name)
{
    SC_METHOD(muxProcess);
    sensitive << in1 << in2 << select;
}

void mux::muxProcess()
{
    out.write(select ? in1 : in2);
}
