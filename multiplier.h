#include "systemc.h"
#include "digit.h"

// Define SC module
template<class T> SC_MODULE(multiplier)
{
    // ports
    sc_in<T> in1, in2;

    sc_out<NN_DIGIT> out;

    // constructor
    SC_CTOR(multiplier)
    {
        SC_METHOD(multiplierProcess);
        sensitive << in1 << in2;
    }

    void multiplierProcess()
    {
        out->write(in1->read() * in2->read());
    }
};