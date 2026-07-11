#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "arrangement/arrangement.h"
#include "blueprint/blueprint.h"
#include "dispatcher/dispatcher.h"
#include "frontend/frontend.h"

// TODO - tests

#define SHUTDOWN(E) { error_status = (E); goto shutdown; }
#define ASSERT(F, E) { if(!(F)) { SHUTDOWN(E); } }

typedef struct processing_resources_t {
	pthread_mutex_t* command_buffer_lock;
} processing_resources_t;

void processing_cleanup(void* data) {
	processing_resources_t resources = *(processing_resources_t*)data;
}

void* processing_loop(void* data) {
	int old_cancelstate = 0;
	processing_resources_t resources = { 0 };

	pthread_cleanup_push(processing_cleanup, &resources);

	while(true) {
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancelstate);

		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &old_cancelstate);
	}

	(void)old_cancelstate;

	pthread_cleanup_pop(1); // required to close `pthread_cleanup_push` macro

	return NULL;
}

void input_loop() {
	while(true) {
		
	}
}

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

	pthread_t processing_thread;

	ASSERT(dispatcher_init(&dispatcher), 10);
	ASSERT(arranger_init(&arranger, dispatch_component), 12);
	ASSERT(frontend_init(&frontend, arranger_update_selection), 13);

	ASSERT(arranger_start(arranger), 100);

	uint32_t blueprint_count = create_blueprints_from_dir(argv[1], &blueprints);
	
	pthread_create(&processing_thread, NULL, processing_loop, NULL);

	input_loop();

shutdown:
	free(blueprints);

	free(frontend);
	free(arranger);
	free(dispatcher);

	exit(error_status);
}
