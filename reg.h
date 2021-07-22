#include "systemc.h"

// Define SC module
SC_MODULE(reg)
{
    // ports
    sc_in<float> in;
    sc_in_clk clock;

    sc_out<float> out;

    // constructor
    SC_CTOR(reg)
    {
        SC_CTHREAD(regProcess, clock.pos());
    }

    void regProcess();
};