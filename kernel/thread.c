#include "proc.c"

int thread_create(thread_obj_t* thread, void(*func)(void*), void* args) {
    struct proc* newproc;
    struct proc* currentproc = myproc();
    if(( newproc = allocproc()) = 0) {
	return -1;
    }

    //Copy over heap and globals, do stack magic to start new while keeping reference to old
    
    thread->pid = newproc->pid;

    release(&newproc->lock);

    acquire(&wait_lock);
    newprocp->parent = currentproc;
    release(&wait_lock);

    acquire(&np->lock);
    newproc->state = RUNNABLE;
    release(&np->lock);

    return 0;
}

int thread_join(thread_obj_t* thread) {
    return 0;
}

int thread_destroy(thread_obj_t* thread) {
    return 0;
}
