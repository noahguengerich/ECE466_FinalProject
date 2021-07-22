#include "systemc.h"

// define SC module
SC_MODULE(fsm_controller)
{
    // ports
    sc_in_clk clock;
    sc_in <bool> hw_enable;

    sc_out <bool> bonus_enable;
    sc_out <bool> hw_done;
    sc_out <bool> latch_input;
    sc_out <bool> latch_output;

    // primitives
    enum fsmState {RESET, IDLE, INPUT, BONUS, OUTPUT, FINISH};
    fsmState state;

    // constructor
    fsm_controller(sc_module_name n);

    // function prototypes
    void fsmProcess();
};