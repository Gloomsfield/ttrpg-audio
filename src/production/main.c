#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "arrangement/arrangement.h"
#include "blueprint/blueprint.h"
#include "dispatcher/dispatcher.h"
#include "frontend/frontend.h"
#include "processing/processing.h"

// TODO - tests

#define SHUTDOWN(E) { error_status = (E); goto shutdown; }
#define ASSERT(F, E) { if(!(F)) { SHUTDOWN(E); } }

int main(int argc, char* argv[]) {
	int error_status = 0;

	if(argc < 2) {
		fprintf(stderr, "please provide a path to the blueprint directory!\n");
		ASSERT(false, 1);
	}

	dispatcher_t* dispatcher = NULL;
	arranger_t* arranger = NULL;
	frontend_t* frontend = NULL;

	blueprint_t* blueprints = NULL;

	pthread_t* processing_thread = NULL;

	ASSERT(dispatcher_init(&dispatcher), 10);
	ASSERT(arranger_init(&arranger, dispatch_component), 12);
	ASSERT(frontend_init(&frontend, arranger_update_selection), 13);

	ASSERT(arranger_start(arranger), 100);

	create_blueprints_from_dir(argv[1], &blueprints);
	
	ASSERT(!pthread_create(processing_thread, NULL, processing_loop, NULL), 101);

	input_loop(NULL /* TODO */);

shutdown:
	if(processing_thread != NULL) { pthread_cancel(*processing_thread); }

	free(blueprints);

	free(frontend);
	free(arranger);
	free(dispatcher);

	exit(error_status);
}
