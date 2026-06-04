#pragma once

#include <stdint.h>
#include <stdbool.h>

void esp_anti_rollback_set_efuse_secure_version(uint32_t version);

uint32_t esp_efuse_read_secure_version(void);

bool esp_efuse_check_secure_version(uint32_t secure_version);