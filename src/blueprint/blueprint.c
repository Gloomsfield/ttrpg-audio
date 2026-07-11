#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "blueprint.h"
#include "parser/parser.h"
#include "utils/files.h"

// TODO - source
// TODO - tests

uint32_t create_blueprints_from_dir(char* directory_path, blueprint_t** result_blueprints) {
	file_contents_t* file_contents = NULL;
	uint32_t file_count = get_file_contents_from_dir(directory_path, &file_contents);

	*result_blueprints = calloc(file_count, sizeof(blueprint_t*));
	uint32_t blueprint_count = 0;

	for(int i = 0; i < file_count; i++) {
		parsed_file_t* parsed_file = NULL;

		if(!parse_file_contents(file_contents[i], &parsed_file)) {
			printf("warning: failed to parse contents in file \"%s\"\n", file_contents[i].filename);

			continue;
		}

		if(!create_blueprint(
			get_info_from_parsed_file(parsed_file),
			get_code_from_parsed_file(parsed_file),
			&(result_blueprints[blueprint_count]))
		) {
			printf("warning: failed to create blueprint from file \"%s\"\n", file_contents[i].filename);
		}

		blueprint_count++;
	}

	free(file_contents);

	*result_blueprints = realloc(*result_blueprints, blueprint_count * sizeof(blueprint_t*));

	return blueprint_count;
}
