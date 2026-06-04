#include "secure_boot.h"

static volatile bool secure_boot_enabled = true;
static volatile bool key_digest_available = true;
static volatile bool signature_valid = true;

bool esp_secure_boot_enabled(void)
{
    return secure_boot_enabled;
}

bool get_secure_boot_key_digests(void)
{
    return key_digest_available;
}

__attribute__((noinline))
bool esp_secure_boot_verify_signature_block(void)
{
    if (esp_secure_boot_enabled())
    {
        if (!get_secure_boot_key_digests())
        {
            return false;
        }

        if (!signature_valid)
        {
            return false;
        }

        return true;
    }

    return true;
}