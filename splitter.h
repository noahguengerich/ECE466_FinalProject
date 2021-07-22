#include "systemc.h"
#include "digit.h"

// Define SC module
SC_MODULE(splitter)
{
    // ports
    sc_in<float> in;

    sc_out<float> outHigh, outLow;

    // constructor
    splitter(sc_module_name name);

    // prototype
    void splitterProcess();
};