#pragma once

#include <stdbool.h>

#include "component/component.h"

typedef struct parsed_file_t parsed_file_t;

bool parse_file_contents(char* file_contents, parsed_file_t* result_file);

bool get_code_from_parsed_file(parsed_file_t* file, char** result_code);
bool get_info_from_parsed_file(parsed_file_t* file, component_info_t* result_info);
