#include "systemc.h"

// Define SC module
SC_MODULE(comparator)
{
    // ports
    sc_in<float> in1, in2;

    sc_out<bool> out;

    // constructor
    comparator(sc_module_name n);

    // prototype
    void comparatorProcess();
};