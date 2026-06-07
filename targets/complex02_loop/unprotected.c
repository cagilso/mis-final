#include <stdint.h>
#include <stdbool.h>

#include "complex02_loop.h"


/*
 * Complex Target Class: Loop
 *
 * This target models a repeated integrity validation process.
 * Multiple firmware blocks contribute to a final verification value.
 * The protected operation is only accepted if all loop iterations
 * contribute to the expected result.
 * 
 * 
 * Security interpretation
 * - each loop iteration validated one firmware block
 * - all firmware blocks must be processed
 * - the firmware block is only accepted if all blocks pass validation
 * 
 * Fault Model
 * - if a loop iteration is skipped, one or more firmware blocks 
 *   may not be validated.
 * - So, validation process becomes imcomplete.
 * 
 * 
 * Relevance
 * - This target evaluates whether the countermeasure can protect 
 * repeated control flow execution with a back edge.
*/


volatile uint32_t loop_result;
bool block_valid[4] = {true, true, true, true};

bool loop_target(void)
{
    uint32_t validated_blocks = 0;

    for (uint32_t i = 0; i < 4; i++) 
    {
        if(block_valid[i])
        {
            validated_blocks++;
        }
    }

    loop_result = validated_blocks;

    return (validated_blocks == 4);
}