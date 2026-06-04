#pragma once
#include <stdbool.h>


bool esp_secure_boot_enabled(void);

bool get_secure_boot_key_digests(void);

bool esp_secure_boot_verify_signature_block(void);