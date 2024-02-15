struct thread_obj_t
{
  int pid;
  void *ret;
};

int thread_create(thread_obj_t *thread, void (*fn)(void *), void *args);
int thread_join(thread_obj_t *thread);
int thread_destroy(thread_obj_t *thread);
