#include <stdint.h>
#include <stdbool.h>

#include "basic03_branch_merge.h"


/*
 * Target Class: Branch + Merge
 *
 * This target models a security decision with two explicit paths
 * that merge again before returning.
 * 
 * 
 * Security interpretation
 *  - invalid signature: deny access
 *  - valid signature:   accept access
 * 
 * Fault Model
 * - Skipping the conditional branch may redirect 
 *   execution into the wrong decision path.
 * - The merge point is relevant because both legitimate paths
 *   continue through a shared finalization block.
 * 
 * Relevance:
 *  This target evaluates whether the countermeasure can handle
 *  branching control flow where different valid paths merge
 *  again before the function exit.
 * 
*/

volatile uint32_t branch_merge_result = 0;

bool branch_merge_target(uint32_t signature_valid)
{
    uint32_t decision;


    if (signature_valid)
    {
        decision = ACCEPT;
    } else {
        decision = DENY;
     }

    /*
     * Merge point:
     * Both the ACCEPT and DENY paths continue here.
    */
    branch_merge_result = decision;

    return (decision == ACCEPT);
}