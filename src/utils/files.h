#pragma once

#include <stdint.h>

typedef struct file_contents_t {
	char* filename;
	char* contents;
} file_contents_t;

uint32_t get_file_contents_from_dir(char* directory_path, file_contents_t** result_contents);
