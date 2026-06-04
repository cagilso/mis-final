#include "anti_rollback.h"

static uint32_t simulated_efuse_secure_version = 5;

/*
 * Simulated eFuse secure version.
 *
 * Firmware image is accepted only if:
 * app_secure_version >= efuse_secure_version
 */

void esp_anti_rollback_set_efuse_secure_version(uint32_t version)
{
    simulated_efuse_secure_version = version;
}

uint32_t esp_efuse_read_secure_version(void)
{
    uint32_t secure_version = simulated_efuse_secure_version;

    return secure_version;
}


/*
    *   
    *   Code-Structure: Simple If
    * 
*/
bool esp_efuse_check_secure_version(uint32_t secure_version)
{
    uint32_t sec_ver_hw = esp_efuse_read_secure_version();
    bool ret_status = (secure_version >= sec_ver_hw); //FI-target

    return ret_status;
}