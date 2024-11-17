#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

const int max = 10;
sem_t s1;

void *tentry_fun1(void *pv) // consumer
{
  int i;
  printf("A--welcome\n");
  sem_wait(&s1);
  for (i = 1; i <= max; i++) {
    printf("A--%d\n", i);
    sleep(1);
  }
  sem_post(&s1);
  // pthread_exit(NULL);
}
void *tentry_fun2(void *pv) // producer
{
  int i;
  printf("B--welcome\n");
  sem_wait(&s1);
  for (i = 1; i <= max; i++) {
    printf("B--%d\n", i);
    sleep(1);
  }
  sem_post(&s1);
  // pthread_exit(NULL);
}
int main() {
  pthread_t pt1, pt2; // thread handle
  sem_init(&s1, 0, 1);
  pthread_create(&pt1, NULL, tentry_fun1, NULL);
  pthread_create(&pt2, NULL, tentry_fun2, NULL);
  pthread_join(pt1, NULL);
  pthread_join(pt2, NULL);
  sem_destroy(&s1);
  printf("main--thank you\n");
  return 0; // exit(0);
}
