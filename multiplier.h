#include "systemc.h"

// Define SC module
SC_MODULE(multiplier)
{
    // ports
    sc_in<float> in1, in2;

    sc_out<float> out;

    // constructor
    multiplier(sc_module_name n);

    // prototype
    void multiplierProcess();
};