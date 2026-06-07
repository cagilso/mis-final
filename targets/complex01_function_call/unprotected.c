#include <stdint.h>
#include <stdbool.h>

#include "complex01_function_call.h"


/*
 * Complex Target Class: Function Call
 *
 * This target models a security decision where a 
 * required verification step is delegated to a 
 * separate function.
 * The protected operation is only accepted if the 
 * called verification routine returns a valid result.
 * 
 * 
 * Security interpretation:
 * - invalid authentication token: deny access
 * - valid authentication token: accept access
 * 
 * Fault Model
 * - if the function call is skipped or returns to wrong location,
 * the security decsion may be bypassed.
 * 
 * 
 * Relevance: 
 * This target evaluates whether the countermeasure can protect
 * control flow across function boundaries, including 
 * call and return edges.
*/

volatile uint32_t function_call_result;

static bool verify_auth_token(bool token_valid)
{
    return token_valid;
}


bool function_call_target(bool token_valid)
{
    uint32_t decision = DENY;

    if(verify_auth_token(token_valid))
    {
        decision = ACCEPT;
    }
    function_call_result = decision;

    return (decision == ACCEPT);
}