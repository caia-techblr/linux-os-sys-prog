#include <pthread.h>
#include <stdio.h>

void *task_body(void *pv) {
  char *ps = pv;
  int i;
  printf("%s--welcome\n", ps);
  for (i = 1; i <= 10; i++)
    printf("%s--%d\n", ps, i);
  long status = 10;
  pthread_exit((void *)status);
}
int main() {
  void *status;
  pthread_t pt1, pt2, pt3; // thread handle
  pthread_create(&pt1, NULL, task_body, "A1");
  pthread_create(&pt2, NULL, task_body, "B2");
  pthread_create(&pt3, NULL, task_body, "C3");
  pthread_join(pt1, &status);
  pthread_join(pt2, NULL);
  pthread_join(pt3, NULL);
  printf("thread exit status is :%ld\n", (long)status);
  printf("main--thank you\n");
  return 0; // exit(0);
}
