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
    struct proc* currentproc = myproc();
    struct proc* childproc = 0; 

    acquire(&wait_lock); 
    for (;;) { // Change this to something that actually makes sense (like checking all threads)
      if (p->pid == thread->pid) {
        childproc = p;
        break;
      }
    }

    while (childproc->state != ZOMBIE) {
      sleep(childproc, &wait_lock);
    }
    release(&wait_lock); 
	
    return 0; 
}

int thread_destroy(thread_obj_t* thread) {
    return kill(thread->pid, SIGKILL);
}
