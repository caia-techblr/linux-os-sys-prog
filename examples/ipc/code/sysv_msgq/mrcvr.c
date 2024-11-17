#include <sys/msg.h>
#include <unistd.h>

#define MQKEY 0x1235

int main() {
  int mqid, nbytes;
  mqid = msgget(MQKEY, IPC_CREAT | 0666);
  if (mqid < 0) {
    perror("msgget");
    exit(1);
  }
  char buf[100];
  int maxlen = 40;

  // nbytes=msgrcv(mqid,buf,maxlen,0,0);
  // nbytes=msgrcv(mqid,buf,maxlen,0,IPC_NOWAIT);
  // nbytes=msgrcv(mqid,buf,12,0,0);
  nbytes = msgrcv(mqid, buf, 12, 0, MSG_NOERROR);

  if (nbytes < 0) {
    perror("msgrcv");
    exit(2);
  }
  buf[nbytes] = '\0';
  printf("nbytes=%d,buf=%s\n", nbytes, buf);
  return 0;
}
