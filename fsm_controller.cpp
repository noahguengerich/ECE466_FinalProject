#include "systemc.h"
#include "fsm_controller.h"

SC_HAS_PROCESS(fsm_controller);

// Contructor
fsm_controller::fsm_controller(sc_module_name n) : sc_module(n), state(RESET)
{
    SC_CTHREAD(fsmProcess, clock.pos());
}

// clocked fsm
void fsm_controller::fsmProcess()
{
    while(true)
    {
        switch(state)
        {
            case RESET:
                hw_done.write(false);
                latch_input.write(false);
                latch_output.write(false);
                bonus_enable.write(false);
                state = IDLE;
                break;

            case IDLE:
                state = ( hw_enable.read() ? INPUT : IDLE );
                break;
            
            case INPUT:
                latch_input.write(true);
                state = PROCESS;
                break;

            case PROCESS:
                latch_input.write(false);
                bonus_enable.write(true);
                state = OUTPUT;
                break;

            case OUTPUT:
                bonus_enable.write(false);
                latch_output.write(true);
                state = FINISH;
                break;

            case FINISH:
                if (hw_enable.read() == true)
                {
                    latch_output.write(false);
                    hw_done.write(true);
                } else {
                    hw_done.write(false);
                    state = IDLE;
                }
                break;

            default:
                printf("Error - default FSM state reached\n");
                sc_stop();
        }
        wait(); // for next clock cycle
    }
}