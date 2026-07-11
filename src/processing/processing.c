#include <stdbool.h>

#include <pthread.h>

#include "processing.h"

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

		// TODO - handle commands

		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &old_cancelstate);
	}

	(void)old_cancelstate;

	pthread_cleanup_pop(1); // required to close `pthread_cleanup_push` macro

	return NULL;
}
