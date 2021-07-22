#include "systemc.h"
#include "subtractor.h"



void subtractor::subtractorProcess()
{
    out->write(x->read() - y->read());
}
