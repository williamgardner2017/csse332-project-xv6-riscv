struct thread_obj_t
{
  int pid;
  void *ret;
};

<<<<<<< HEAD
int thread_create((struct thread_obj_t) *t, void (*fn)(void *), void *arg);
=======
int thread_create(struct thread_obj_t *t, void (*fn)(void *), void *arg);
>>>>>>> bb0001e21a194c517a83420bf8937320135b716f
int thread_join(struct thread_obj_t *thread);
int thread_destroy(struct thread_obj_t *thread);
