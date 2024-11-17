#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int ret, i, max = 10, status;
  printf("welcome..pid=%d\n", getpid());
  sem_t *ps, *qs;
  ps = sem_open("s1", O_CREAT, 0666, 1);
  qs = sem_open("s2", O_CREAT, 0666, 0);
  ret = fork();
  if (ret == 0) {
    printf("child--welcome,pid=%d,ppid=%d\n", getpid(), getppid());
    sem_wait(ps);
    for (i = 1; i <= max; i++) {
      printf("child--%d\n", i);
      sleep(1);
    }
    sem_post(ps);
    sem_post(qs);
    exit(0);
  } else // ret>0
  {
    printf("parent--hello,pid=%d,ppid=%d\n", getpid(), getppid());
    sem_wait(ps);
    sem_wait(qs);
    for (i = 1; i <= max; i++) {
      printf("parent--%d\n", i);
      sleep(1);
    }
    sem_post(ps);
    waitpid(-1, &status, 0);
    sem_unlink("s1");
    // sem_unlink("s2");
  }
  // printf("thank you,pid=%d,ppid=%d\n",
  //		getpid(),getppid());
  return 0;
}
/** TODO:- locate named semaphore in /dev/shm before unlinking */
