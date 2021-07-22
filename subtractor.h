#include "systemc.h"

// Define SC module
SC_MODULE(subtractor)
{
    // ports
    sc_in<float> x;
    sc_in<float> y;

    sc_out<float> out;

    // constructor
    SC_CTOR(subtractor)
    {
        SC_METHOD(subtractorProcess);
        sensitive << x << y;
    }

    void subtractorProcess();
};