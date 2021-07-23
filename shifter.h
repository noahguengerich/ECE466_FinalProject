#include "systemc.h"
#include "digit.h"

// Define SC module
SC_MODULE(shifter)
{
    // ports
    sc_in<NN_DIGIT> in;
    sc_in<int> shift;

    sc_out<NN_DIGIT> out;

    // constructor
    shifter(sc_module_name n);

    // prototype
    void shifterProcess();
};