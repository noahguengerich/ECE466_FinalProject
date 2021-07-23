#ifndef _DH_HW_H_
#define _DH_HW_H_ 1

#include "systemc.h"
#include "digit.h"
#include "reg.h"
#include "fsm_controller.h"
#include "bonus_module.h"
#include "comparator.h"
#include "multiplier.h"
#include "mux.h"
#include "shifter.h"
#include "splitter.h"
#include "subtractor.h"

SC_MODULE(dh_hw)
{
    // Ports
    sc_in<NN_DIGIT> from_sw0, from_sw1, from_sw2;
    sc_in<NN_HALF_DIGIT> from_sw3;
    sc_in<bool> hw_enable;
    sc_in_clk clock;

    sc_out<NN_DIGIT> to_sw0, to_sw1;
    sc_out<NN_HALF_DIGIT> to_sw2;    
    sc_out<bool> hw_done;

    // SystemC Components
    fsm_controller FSM;
    bonus_module bonus;

    reg reg0;
    reg reg1;
    reg reg2;
    reg reg3;
    reg reg4;
    reg reg5;
    reg reg6;

    splitter split0;

    multiplier multi0;
    multiplier multi1;

    shifter shift0;
    shifter shift1;

    subtractor sub0;
    subtractor sub1;
    subtractor sub2;
    subtractor sub3;
    subtractor sub4;

    comparator comp0;

    // SystemC Signals
    // Signals are named by their driving source (e.g. shift1 is driven by shifter 1)
    sc_signal <NN_DIGIT> t0;
    sc_signal <NN_DIGIT> t1;
    sc_signal <NN_DIGIT> c;

    sc_signal <NN_HALF_DIGIT> aHigh;
    sc_signal <NN_HALF_DIGIT> cHigh;
    sc_signal <NN_HALF_DIGIT> cLow;

    sc_signal <NN_DIGIT> u;
    sc_signal <NN_DIGIT> v;

    sc_signal <NN_DIGIT> shift0;
    sc_signal <NN_DIGIT> shift1;

    sc_signal <NN_DIGIT> sub0;
    sc_signal <NN_DIGIT> sub1;
    sc_signal <NN_DIGIT> sub2;
    sc_signal <NN_DIGIT> sub3;
    sc_signal <NN_DIGIT> sub4;

    sc_signal <NN_DIGIT> comp0;

    sc_signal <NN_DIGIT> t0_out;
    sc_signal <NN_DIGIT> t1_out;
    sc_signal <NN_DIGIT> aHigh_out;

    sc_signal <bool> latch_input;
    sc_signal <bool> latch_output;
    sc_signal <bool> bonus_enable;

    sc_signal<NN_DIGIT> shift0_val;
    sc_signal<NN_DIGIT> shift1_val;
    sc_signal<NN_DIGIT> sub1_val;

    // constructor
    dh_hw(sc_module_name n);
};

#endif /* end _DH_HW_H_ */
