#pragma once

#include <stdint.h>

typedef uint32_t hash_key_t;

hash_key_t hash_from_string(char* string);
