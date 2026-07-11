#pragma once

#include <stdbool.h>

#include "component/component.h"

typedef struct dispatcher_t dispatcher_t;

bool dispatcher_init(dispatcher_t** dispatcher);

bool dispatch_component(dispatcher_t* dispatcher, component_t* component);
