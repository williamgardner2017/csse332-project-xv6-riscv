#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/thread.h"
#include "user/user.h"

int main(int argc, char* argv[]) {
    printf("TESTING\n");
    struct thread_obj_t* testThread = malloc(sizeof(struct thread_obj_t*));
    thread_create(testThread, test_fn, NULL);
    sleep(5);
    printf("killing thread now\n");
    thread_destroy(testThread);
    if(testThread->pid == 0) {
	printf("properly destroyed\n");
    }
    else {
	printf("Did not destroy properly\n");
    }
    printf("Creating a new thread\n");
    thread_create(testThread, test_fn, NULL);
    thread_join(testThread);
    if((int) testThread->ret == (int) 5) {
	printf("We joined right\n");
    }
    else {
	printf("We joined wrong\n");
    }
    exit(0);
}

void* test_fn(void* args) {
    printf("eyyy i'm functioning here\n");
    sleep(10);
    return (void*) 5;
}
