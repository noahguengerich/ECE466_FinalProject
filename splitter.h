#include "systemc.h"
#include "digit.h"

// Define SC module
SC_MODULE(splitter)
{
    // ports
    sc_in<NN_DIGIT> in;

    sc_out<NN_HALF_DIGIT> outHigh, outLow;

    // constructor
    splitter(sc_module_name name);

    // prototype
    void splitterProcess();
};