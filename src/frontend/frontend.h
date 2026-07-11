#pragma once

#include <stdbool.h>

#include "arrangement/arrangement.h"

typedef struct frontend_t frontend_t;

bool frontend_init(frontend_t* frontend, void(* on_selection_changed)(arranger_t*, selection_info_t*));

bool frontend_start(frontend_t* frontend);
