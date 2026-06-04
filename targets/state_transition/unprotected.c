#include "state_transition.h"

/*
 * Code-Structure: State-dependent
 *
 * Expected execution path:
 * AUTH: token += 1
 * VERIFY: token += 2
 * COMMIT: token += 4
 *
 * Final token = 1 + 2 + 4 = 7
 */

bool state_progress_unprotected(bool auth_ok, bool verify_ok)
{
    unsigned int state = 0;
    unsigned int token = 0;

    /* AUTH phase */

    state = state+1;      
    token += 1;     

    if (!auth_ok) {
        return false;
    }

    // verify

    state = state+1;       
    token += 2;      

    if (!verify_ok) {
        return false;
    }

    // commit

    state = state+1;       
    token += 4;      

    return (state == 3 && token == 7);
}