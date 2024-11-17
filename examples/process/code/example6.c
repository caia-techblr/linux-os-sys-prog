#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t ret;
  printf("welcome...pid=%d\n", getpid());
  ret = fork();
  if (ret < 0) {
    perror("fork");
    exit(1);
  }
  if (ret == 0) {
    printf("child--hello,pid=%d,ppid=%d\n", getpid(), getppid());
    int k;
    // char* argv[]={"cal","10","2018",NULL};
    // k=execv("/usr/bin/cal",argv);
    k = execl("/usr/bin/cal", "cal", "10", "2021", NULL);
    if (k < 0) {
      perror("execv");
      exit(1);
    }
    exit(0);
  } else // ret>0
  {
    printf("parent--hello,pid=%d,ppid=%d\n", getpid(), getppid());
  }
  // printf("Thank you..pid=%d\n",getpid());
  return 0;
}
