#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "component/component.h"

typedef struct blueprint_t blueprint_t;

bool create_blueprint(component_info_t info, char* code, blueprint_t** result_blueprint);

uint32_t create_blueprints_from_dir(char* directory_path, blueprint_t** result_blueprints);

bool build_blueprint(blueprint_t* blueprint, component_t* result_component);
