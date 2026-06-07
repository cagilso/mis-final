#include <stdint.h>
#include <stdbool.h>

#include "advanced01_early_exit.h"


/*
 * Advanced Target Class: Early Exit
 *
 * This target models a security decision where the function
 * exits immediately if a required check fails.
 * The protected operation is only reached if the early
 * rejection path is not taken.
 * 
 * 
 * Security interpretation
 * - outdated firmware version: deny access immediately
 * - allowed firmware version:   continue and accept access
 * 
 * 
 * Fault Model
 * - If the rejection path is skipped, an invalid input 
 *   may reach the accept decision.
 * 
 * 
 * Relevance
 * This target evaluates whether the countermeasure can protect
 * control flow with an early rejection path, which is common 
 * in security checks, such as signature verification, authentication
 * and anti-rollback validation.
 * 
*/



volatile uint32_t early_exit_result;

bool early_exit_target(uint32_t version_allowed)
{
    if (!version_allowed)
    {
        early_exit_result = DENY;
        return false; 
    }
    early_exit_result = ACCEPT;
    return true;
}

