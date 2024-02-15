struct thread_obj_t
{
  int pid;
  void *ret;
};

typedef void (fn_t)(void *);

int thread_create(struct thread_obj_t *t, fn_t* fn, void *arg);
int thread_join(struct thread_obj_t *thread);
int thread_destroy(struct thread_obj_t *thread);
