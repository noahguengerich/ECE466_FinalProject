#include "systemc.h"

// Define SC module
SC_MODULE(shifter)
{
    // ports
    sc_in<float> in;
    sc_in<int> shift;

    sc_out<float> out;

    // constructor
    shifter(sc_module_name n);

    // prototype
    void shifterProcess();
};