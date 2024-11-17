#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

const int max = 100000;
int val = 100;

sem_t sm;

void *efun1(void *pv) {
  int i;
  printf("A--welcome\n");
  for (i = 1; i <= max; i++) {
    sem_wait(&sm);
    val++;
    sem_post(&sm);
  }
}
void *efun2(void *pv) {
  int i;
  printf("B--welcome\n");
  for (i = 1; i <= max; i++) {
    sem_wait(&sm);
    val--;
    sem_post(&sm);
  }
}
int main() {
  printf("main--Welcome\n");
  pthread_t pt1, pt2; // thread handles
  sem_init(&sm, 0, 1);
  pthread_create(&pt1, NULL, efun1, NULL);
  pthread_create(&pt2, NULL, efun2, NULL);
  pthread_join(pt1, NULL);
  pthread_join(pt2, NULL);
  sem_destroy(&sm);
  printf("main--Thank you,final val=%d\n", val);
  return 0;
}
