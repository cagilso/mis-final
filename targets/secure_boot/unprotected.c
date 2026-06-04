#include "secure_boot.h"

/*
 * Simplified Secure Boot model
 */

static bool secure_boot_enabled = true;
static bool key_digest_available = true;
static bool signature_valid = true;


bool esp_secure_boot_enabled(void)
{
    return secure_boot_enabled;
}


bool get_secure_boot_key_digests(void)
{
    return key_digest_available;
}


/*
    *
    *   Code-Structure: Nested If
    * 
*/
bool esp_secure_boot_verify_signature_block(void)
{
    if (!get_secure_boot_key_digests())
    {
        if (esp_secure_boot_enabled())
        {
            return false;   
        }
    }

    if (signature_valid)
    {
        return true;        // FI target
    }
    return false;
}
