#include "dummy.h"
#include "trigger.h"

#include <stdbool.h>

__attribute__((noinline))
bool dummy_fault_window_unprotected(void)
{
    volatile int value = 0;

    trigger_high();

    value = 0x10;   
    
    __asm__ volatile (
        "nop\n"
        "nop\n"
        "nop\n"
    );

    volatile bool correct = (value == 0x10);

    __asm__ volatile (
        "nop\n"
        "nop\n"
        "nop\n"
    );

    trigger_low();

    return correct;
}