#include "bonus_module.h"

SC_HAS_PROCESS(bonus_module);

bonus_module::bonus_module(sc_module_name n) : sc_module(n)
{
    SC_METHOD(bonusProcess);
    sensitive << bonus_enable;
}

void bonus_module::bonusProcess()
{
    if (bonus_enable.read() == true)
    {
        // Load initial values
        NN_DIGIT t[2];
        t[0] = t0.read();
        t[1] = t1.read();

        NN_HALF_DIGIT aHigh = aHigh_in.read();
        NN_HALF_DIGIT cHigh = cHigh_in.read();
        NN_HALF_DIGIT cLow = cLow_in.read();

        // Process (code from provided dh_hw.cpp)
        while ((t[1] > cHigh) || ((t[1] == cHigh) && (t[0] >= TO_HIGH_HALF (cLow)))) 
        {
            if ((t[0] -= TO_HIGH_HALF (cLow)) > MAX_NN_DIGIT - TO_HIGH_HALF (cLow)) t[1]--;
            t[1] -= cHigh;
            aHigh++;
        }

        // Write outputs
        t0_out.write(t[0]);
        t1_out.write(t[1]);
        aHigh_out.write(aHigh);
    }    
}