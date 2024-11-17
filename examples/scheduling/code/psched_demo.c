#define _GNU_SOURCE

#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

const int max = 20;
void *task_body1(void *pv) {
  int i;
  printf("A--welcomei,tid=%ld\n", syscall(SYS_gettid));
  for (i = 1; i <= max; i++) {
    printf("A---%d\n", i);
    sleep(1);
  }
  // pthread_exit
}
void *task_body2(void *pv) {
  int i;
  printf("B--welcome,tid=%ld\n", syscall(SYS_gettid));
  for (i = 1; i <= max; i++) {
    printf("B--%d\n", i);
    sleep(1);
  }
  // pthread_exit
}
int main() {
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_attr_setschedpolicy(&attr, SCHED_FIFO); // sudo

  struct sched_param p1;
  p1.sched_priority = 50;
  pthread_attr_setschedparam(&attr, &p1);

  cpu_set_t mask;
  CPU_ZERO(&mask);
  CPU_SET(0, &mask);
  // CPU_SET(2,&mask);
  pthread_attr_setaffinity_np(&attr, sizeof(mask), &mask);

  pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

  int ret;
  pthread_t pt1, pt2;
  ret = pthread_create(&pt1, &attr, task_body1, NULL);
  if (ret)
    fprintf(stderr, "pthread_create failed:%s\n", strerror(ret));
  ret = pthread_create(&pt2, &attr, task_body2, NULL);
  if (ret)
    fprintf(stderr, "pthread_create failed:%s\n", strerror(ret));
  printf("For main thread..tid=%ld\n", syscall(SYS_gettid));
  pthread_join(pt1, NULL);
  pthread_join(pt2, NULL);
  printf("Main--thank you\n");
  return 0; // exit(0)
}
