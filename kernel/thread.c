#include "proc.c"
#include "thread.h"

int thread_join(struct thread_obj_t *thread)
{
  // struct proc *currentproc = myproc();
  // struct proc *childproc = 0;

  // acquire(&wait_lock);
  // for (struct proc *p = proc; p < &proc[NPROC]; p++) {
  //   if (p->pid == thread->pid && p->parent == currentproc) {
  //     childproc = p;
  //     break;
  //   }
  // }

  // if (!childproc) {
  //   release(&wait_lock);
  //   return -1; // Thread not found
  // }

  // while (childproc->state != ZOMBIE) {
  //   sleep(childproc, &wait_lock);
  // }
  // release(&wait_lock);

  return 0;
}

int thread_destroy(struct thread_obj_t *thread)
{
  int ret = kill(thread->pid);
  if (ret == -1)
  {
    return -1;
  }
  thread->pid = 0;
  return 0;
}
