#pragma once

#include <stdint.h>

#include "blueprint/blueprint.h"
#include "component/component.h"

typedef struct arranger_t arranger_t;

typedef struct selection_info_t {
	component_info_t* components;
	uint32_t n;
} selection_info_t;

bool arranger_init(arranger_t* arranger, void(* on_component_built)(component_t* new_component));
bool arranger_start(arranger_t* arranger);

void arranger_update_selection(arranger_t* arranger, selection_info_t* new_selection);

void arranger_register_blueprint(arranger_t* arranger, blueprint_t* new_blueprint);
