struct thread_obj_t
{
  int pid;
  void *ret;
};

int thread_create(struct thread_obj_t *thread, void (*fn)(void *), void *args);
int thread_join(struct thread_obj_t *thread);
int thread_destroy(struct thread_obj_t *thread);
