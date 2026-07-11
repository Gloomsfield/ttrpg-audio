#pragma once

#include <stdbool.h>

#include "utils/hash.h"

typedef struct map_t map_t;

void insert_into_map_hash(map_t* map, hash_key_t hashed_key, void* value);
void insert_into_map_str(map_t* map, const char* key, void* value);

void remove_from_map_hash(map_t* map, hash_key_t hashed_key);
void remove_from_map_str(map_t* map, const char* key);

bool get_from_map_hash(map_t* map, hash_key_t hashed_key, void* result_value);
bool get_from_map_str(map_t* map, const char* key, void* result_value);
