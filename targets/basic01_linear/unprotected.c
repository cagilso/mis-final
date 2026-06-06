#include <stdint.h>
#include <stdbool.h>

/*
 * Simple Target Class: Linear execution
 *
 * This target models a simple multi-step security decision.
 * The operation is only considered valid if all required
 * checks are executed in sequence.
 * 
 * Security interpretation:
 *  - step1: firmware-header was parsed
 *  - step2: firmware version was checked 
 *  - step3: security-policy was checked 
 * 
 * Fault Model:
 *  if an instruction skip removes one of the linear steps,
 *  the final progress valued differes from the expected value, 
 *  and the target returns false.
 * 
 * Relevance:
 *  This is the baseline case for evaluating whether the 
 *  countermeasure can protect sequential execution without 
 *  branches, merges, function calls or loops.
 * 
*/


volatile uint32_t value = 0;

bool linear_target(void)
{
    int checks_passed = 0;

    // Fault on
    checks_passed++;
    checks_passed++;
    checks_passed++;

    value = checks_passed;

    // The operation is accepted only if all linear steps ran.
    return (value == 3);
}