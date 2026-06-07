#include <stdint.h>
#include <stdbool.h>

#include "advanced02_nested_decisions.h"


/*
 * Adavnaced Target Class: Nested Decisions
 *
 * This target models a security decision with multiple
 * dependent checks. 
 * The 2nd check is only evaluated if the first check 
 * has already passed.
 * 
 * 
 * Security interpreation
 * - outdated firmware version: deny access
 * - invalid firmware signature: deny access
 * - allowed firmware version and signature: accept access
 * 
 * 
 * Fault Model
 * - If one of the nested decision points is skipped, 
 *   an invalid input may reach the accept decision.
 * 
 * 
 * Relevance
 * - This target evaluates whether the countermeasure can
 * protect multiple dependent control flow decisions.
*/

volatile uint32_t nested_decision_result;

bool nested_decision_target(bool version_allowed, bool signature_valid){
    uint32_t decision = DENY;

    if(version_allowed)
    {
        if(signature_valid)
        {
            decision = ACCEPT;
        }
    }
    nested_decision_result = decision; 

    return (decision == ACCEPT);
}
