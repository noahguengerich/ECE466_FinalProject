#include "systemc.h"

// Define SC module
SC_MODULE(mux)
{
    // ports
    sc_in<float> in1, in2;
    sc_in<bool> select;

    sc_out<float> out;

    // constructor
    mux(sc_module_name n);

    // prototype
    void muxProcess();
};