#include "systemc.h"
//#include "digit.h"
#include "dh_hw.h"

SC_HAS_PROCESS(dh_hw);

dh_hw::dh_hw(sc_module_name n) : 
    sc_module(n), 
    FSM("FSM"),
    bonus("bonus"),
    reg0("reg0"), reg1("reg1"), reg2("reg2"), reg3("reg3"), reg4("reg4"), reg5("reg5"), reg6("reg6"),
    split0("split0"),
    multi0("multi0"), multi1("multi1"),
    shift0("shift0"), shift1("shift1"),
    sub0("sub0"), sub1("sub1"), sub2("sub2"), sub3("sub3"), sub4("sub4"),
    comp0("comp0")
{
    // signal instantiation
    shift0_val.write(-16);
    shift1_val.write(16);
    sub1_val.write(0xffffffff);

    // module instantiation
    FSM.clock(clock);
    FSM.hw_enable(hw_enable);
    FSM.hw_done(hw_done);
    FSM.latch_input(latch_input);
    FSM.latch_output(latch_output);
    FSM.bonus_enable(bonus_enable);

    bonus.t0(sub0_out);
    bonus.t1(sub4_out);
    bonus.aHigh_in(aHigh);
    bonus.cHigh_in(cHigh);
    bonus.cLow_in(cLow);
    bonus.bonus_enable(bonus_enable);
    bonus.t0_out(t0_out);
    bonus.t1_out(t1_out);
    bonus.aHigh_out(aHigh_out);

    reg0.clock(latch_input);
    reg0.in(from_sw0);
    reg0.out(t0);

    reg1.clock(latch_input);
    reg1.in(from_sw1);
    reg1.out(t1);

    reg2.clock(latch_input);
    reg2.in(from_sw2);
    reg2.out(c);

    reg3.clock(latch_input);
    reg3.in(from_sw3);
    reg3.out(aHigh);

    reg4.clock(latch_output);
    reg4.in(t0_out);
    reg4.out(to_sw0);

    reg5.clock(latch_output);
    reg5.in(t1_out);
    reg5.out(to_sw1);

    reg6.clock(latch_output);
    reg6.in(aHigh_out);
    reg6.out(to_sw2);

    split0.in(c);
    split0.outHigh(cHigh);
    split0.outLow(cLow);

    multi0.in1(cHigh);
    multi0.in2(aHigh);
    multi0.out(v);

    multi1.in1(cLow);
    multi1.in2(aHigh);
    multi1.out(u);

    shift0.in(u);
    shift0.shift(shift0_val);
    shift0.out(shift0_out);

    shift1.in(u);
    shift1.shift(shift1_val);
    shift1.out(shift1_out);

    sub0.x(t0);
    sub0.y(shift0_out);
    sub0.out(sub0_out);

    sub1.x(sub1_val);
    sub1.y(shift0_out);
    sub1.out(sub1_out);

    sub2.x(t1);
    sub2.y(comp0_out);
    sub2.out(sub2_out);

    sub3.x(sub2_out);
    sub3.y(shift1_out);
    sub3.out(sub3_out);

    sub4.x(sub3_out);
    sub4.y(v);
    sub4.out(sub4_out);

    comp0.in1(sub0_out);
    comp0.in2(sub1_out);
    comp0.out(comp0_out);
}