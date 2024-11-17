#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

const int max = 10;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
sem_t s1;

void *efun1(void *pv) // producer
{
  int i;

  printf("A--welcome\n");
  pthread_mutex_lock(&m1);
  for (i = 1; i <= max; i++) {
    printf("A--%d\n", i);
    sleep(1);
  }
  pthread_mutex_unlock(&m1);
  sem_post(&s1);
  // pthread_exit(NULL);
}
void *efun2(void *pv) // consumer
{
  int i;
  printf("B--welcome,waiting for semaphore\n");
  sem_wait(&s1); // changing sequence lead to deadlock
  pthread_mutex_lock(&m1);
  for (i = 1; i <= max; i++) {
    printf("B--%d\n", i);
    sleep(1);
  }
  pthread_mutex_unlock(&m1);
  // pthread_exit(NULL);
}
int main() {
  printf("main--Welcome\n");
  pthread_t pt1, pt2; // thread handles
  sem_init(&s1, 0, 0);
  pthread_create(&pt1, NULL, efun1, NULL);
  pthread_create(&pt2, NULL, efun2, NULL);
  // 1st arg -- addr of pthread_t variable
  // 2nd arg -- atributes, NULL -- default
  // 3rd arg -- name/address of entry function
  // 4th arg -- arguments to entry function
  pthread_join(pt1, NULL);
  pthread_join(pt2, NULL);
  sem_destroy(&s1);
  printf("main--Thank you\n");
  return 0;
}
