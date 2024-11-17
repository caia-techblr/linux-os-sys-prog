#include <sys/msg.h>
#include <unistd.h>

#define MQKEY 0x1235

int main() {
  int mqid, ret;
  mqid = msgget(MQKEY, IPC_CREAT | 0666);
  if (mqid < 0) {
    perror("msgget");
    exit(1);
  }
  char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
  int len = sizeof(str);

  ret = msgsnd(mqid, str, len, 0);
  if (ret < 0) {
    perror("msgsnd");
    exit(2);
  }
  printf("msg sent successfully\n");
  return 0;
}
