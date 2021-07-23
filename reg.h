#include "systemc.h"
#include "digit.h"

// Define SC module
template<class T> SC_MODULE(reg)
{
    // ports
    sc_in<T> in;
    sc_in_clk clock;

    sc_out<T> out;

    // constructor
    SC_CTOR(reg)
    {
        SC_CTHREAD(regProcess, clock.pos());
    }

    void regProcess()
    {
        while(1)
        {
            out.write(in->read());
            wait();
        }
    }
};