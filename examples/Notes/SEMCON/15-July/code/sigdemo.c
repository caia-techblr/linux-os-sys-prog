#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

void handler_for_int(int signo) {
  printf("You can't interrupt me\n");
}
void handler_for_quit(int signo) {
  printf("You can't quit me\n");
}
void handler_for_tstp(int signo) {
  printf("You can't suspend me\n");
}
void handler_for_term(int signo) {
  printf("You may terminate, please wait,i'll exit my self\n");
  //some work
  exit(1);
}

int main() {
  printf("pid : %d\n", getpid());
  signal(SIGINT, handler_for_int);
  signal(SIGQUIT, handler_for_quit);
  signal(SIGTSTP, handler_for_tstp);
  signal(SIGTERM, handler_for_term);
  while(1)
    sleep(1); //pause();
  return 0;
}
