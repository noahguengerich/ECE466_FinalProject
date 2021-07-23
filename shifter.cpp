#include "systemc.h"
#include "shifter.h"


// constructor
SC_HAS_PROCESS(shifter);

shifter::shifter(sc_module_name name) : sc_module(name)
{
    SC_METHOD(shifterProcess);
    sensitive << in;
}

void shifter::shifterProcess()
{
    int shiftVal = shift.read();
    out->write(shiftVal > 0 ? in.read() >> shiftVal : in.read() << shiftVal);
}
