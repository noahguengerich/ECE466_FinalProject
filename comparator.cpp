#include "systemc.h"
#include "comparator.h"


// constructor
SC_HAS_PROCESS(comparator);

comparator::comparator(sc_module_name name) : sc_module(name)
{
    SC_METHOD(comparatorProcess);
    sensitive << in1 << in2;
}

void comparator::comparatorProcess()
{
    float in1Val = in1.read();
    float in2Val = in2.read();
    out.write(in1Val > in2Val? 1 : 0);
}
