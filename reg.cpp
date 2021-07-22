#include "systemc.h"
#include "reg.h"

void reg::regProcess()
{
    while(1)
    {
        out.write(in.read());
        wait();
    }
}