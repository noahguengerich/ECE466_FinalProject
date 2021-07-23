#include "systemc.h"
#include "digit.h"

// define SC module
SC_MODULE(bonus_module)
{
    // ports
    sc_in<NN_DIGIT> t0, t1;
    sc_in<NN_HALF_DIGIT> aHigh_in, cHigh_in, cLow_in;
    sc_in<bool> bonus_enable;

    sc_out<NN_DIGIT> t0_out, t1_out;
    sc_out<NN_HALF_DIGIT> aHigh_out;

    // contructor
    bonus_module(sc_module_name n);

    // function prototypes
    void bonusProcess();
};