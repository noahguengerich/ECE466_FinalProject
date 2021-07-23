#include "systemc.h"
#include "digit.h"

// Define SC module
SC_MODULE(comparator)
{
    // ports
    sc_in<NN_DIGIT> in1, in2;

    sc_out<NN_DIGIT> out;

    // constructor
    comparator(sc_module_name n);

    // prototype
    void comparatorProcess();
};