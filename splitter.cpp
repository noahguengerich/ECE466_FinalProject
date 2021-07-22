#include "systemc.h"
#include "splitter.h"

SC_HAS_PROCESS(splitter);

// constructor
splitter::splitter(sc_module_name name) : sc_module(name)
{
    SC_METHOD(splitterProcess);
    sensitive << in;
}

void splitter::splitterProcess()
{
    NN_DIGIT input = in.read();
    outHigh.write(NN_HALF_DIGIT(HIGH_HALF(input)));
    outLow.write(NN_HALF_DIGIT(LOW_HALF(input)));
}
