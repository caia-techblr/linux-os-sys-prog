#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler_for_int(int signo) { printf("You can't interrupt me\n"); }
void handler_for_quit(int signo) { printf("You can't quit me\n"); }
void handler_for_tstp(int signo) { printf("You can't suspend me\n"); }
void handler_for_term(int signo) {
  printf("You may terminate me, but please wait\n");
  exit(0);
}

int main() {
  printf("Welcome,pid=%d\n", getpid());
  signal(SIGINT, handler_for_int);
  signal(SIGQUIT, handler_for_quit);
  signal(SIGTERM, handler_for_term);
  signal(SIGTSTP, handler_for_tstp);
  while (1)
    pause();
  return 0;
}
