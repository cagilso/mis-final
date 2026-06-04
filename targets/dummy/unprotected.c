#include "dummy.h"
#include "trigger.h"

#include <stdbool.h>

/*
    *
    *   Code-Structure: Das was mein Betreuer will
    * 
*/


bool dummy_fault(void)
{
    trigger_high();

    volatile int value = 0x10;

    __asm__ volatile (
        "nop\n"
        "nop\n"
        "nop\n"
    );

    bool correct = (value == 0x10);

    __asm__ volatile (
        "nop\n"
        "nop\n"
        "nop\n"
    );

    trigger_low();

    return correct;
}