#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/thread.h"
#include "user/user.h"

int main(int argc, char* argv[]) {
    printf("TESTING\n");
    struct thread_obj_t* testThread = malloc(sizeof(struct thread_obj_t*);
    thread_create(testThread, test_fn, NULL);
    sleep(5);
    printf("killing thread now");
    thread_destroy(testThread);

    exit(0);
}

void* test_fn(void* args) {
    printf("eyyy i'm functioning here\n");

}
