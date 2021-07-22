#include "systemc.h"
#include "multiplier.h"


// constructor
SC_HAS_PROCESS(multiplier);

multiplier::multiplier(sc_module_name name) : sc_module(name)
{
    SC_METHOD(multiplierProcess);
    sensitive << in1 << in2;
}

void multiplier::multiplierProcess()
{
    out->write(in1.read() * in2.read());
}
