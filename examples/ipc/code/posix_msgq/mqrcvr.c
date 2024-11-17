#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>

int main() {
  int ret, nbytes;
  // struct mq_attr attr;
  // attr.mq_msgsize=512;
  // attr.mq_maxmsg=10;
  mqd_t mqid;
  // mqid=mq_open("/mque2",O_RDONLY|O_CREAT,0666,&attr);
  mqid = mq_open("/mque2", O_RDONLY | O_CREAT, 0666, NULL);
  if (mqid < 0) {
    perror("mq_open");
    exit(1);
  }
  char buf[8192];
  int maxlen = 1024, prio;
  nbytes = mq_receive(mqid, buf, maxlen, &prio);
  if (nbytes < 0) {
    perror("mq_recv");
    exit(2);
  }
  buf[nbytes] = '\0';
  printf("receive msg:%s,nbytes=%d,prio=%d\n", buf, nbytes, prio);
  write(1, buf, nbytes);
  mq_close(mqid);
  return 0;
}
