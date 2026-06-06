#include <stdbool.h>
#include <stdint.h>
#include "basic01_single_branch.h"



/*
 * Simple Target Class: Single branch
 *
 * This target models a minimal security decision.
 * A protected operation is only allowed if a 
 * single authorized condition is satisfied. 
 * 
 * Security interpretation:
 *  - unauthorized request: deny access
 *  - authorized request:   accept access
 * 
 * Fault Model
 *  - Skipping the conditional check or branch 
 *    may change the decision from deny to accept.
 * 
 * Relevance:
 *  This is the baseline case for evaluating whether the
 *  countermeasure can protect a simple control-lfow decision.
 * 
*/

volatile uint32_t branch_result;

bool single_branch_target(uint32_t authorized)
{
    uint32_t decision = DENY;

    if (authorized) {
        decision = ACCEPT;
    }

    branch_result = decision;

    return (decision == ACCEPT);
}