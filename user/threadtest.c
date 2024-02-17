#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void test_fn(void *args)
{   
    printf("%d\n", args);
    printf("eyyy i'm functioning here\n");
    sleep(10);
    printf("time to return baybee\n");
    exit(0);
}

void test_fn_2(void *args) {
    printf("we loopin here\n");
    for(;;)
        ;
}

int main(int argc, char* argv[]) {
    printf("TESTING\n");
    int pid = thread_create(test_fn_2, 0);
    printf("create worked\n");
    sleep(10);
    printf("killing thread now\n");
    thread_destroy(pid);
    printf("thread obliterated\n");
    printf("Creating a new thread\n");
    pid = thread_create(test_fn, 0);
    thread_join(pid);
    printf("joined the 2nd thread\n");
    exit(0);
}

