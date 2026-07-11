#pragma once

#include <stdbool.h>

#include "component/component.h"

#include "utils/files.h"

typedef struct parsed_file_t parsed_file_t;

bool parse_file_contents(file_contents_t file_contents, parsed_file_t** result_file);

char* get_code_from_parsed_file(parsed_file_t* file);
component_info_t get_info_from_parsed_file(parsed_file_t* file);
