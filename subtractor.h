#include "systemc.h"
#include "digit.h"

// Define SC module
SC_MODULE(subtractor)
{
    // ports
    sc_in<NN_DIGIT> x;
    sc_in<NN_DIGIT> y;

    sc_out<NN_DIGIT> out;

    // constructor
    SC_CTOR(subtractor)
    {
        SC_METHOD(subtractorProcess);
        sensitive << x << y;
    }

    void subtractorProcess();
};