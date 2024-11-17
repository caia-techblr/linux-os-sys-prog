#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>

int main() {
  int ret;
  mqd_t mqid;
  mqid = mq_open("/mque2", O_WRONLY | O_CREAT, 0666, NULL);
  if (mqid < 0) {
    perror("mq_open");
    exit(1);
  }
  char str[] = "Hello Message queue";
  int len = strlen(str);
  ret = mq_send(mqid, str, len, 5);
  if (ret < 0) {
    perror("mq_send");
    exit(2);
  }
  mq_close(mqid);
  return 0;
}
