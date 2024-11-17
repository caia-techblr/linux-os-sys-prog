#include <unistd.h>

int main() {
  int ret;
  int fds[2];
  ret = pipe(fds); // fds[0]-RD, fds[1]-WR
  if (ret < 0) {
    perror("pipe");
    exit(1);
  }
  ret = fork();
  if (ret == 0) // child--read
  {
    close(fds[1]); // no write
    char buf[128];
    // blocks if pipe is empty
    nbytes = read(fds[0], buf, 128);
    // err handling
    write(1, buf, nbytes);
    close(fds[0]); // no read
    exit(0);
  } else // parent -- write
  {
    close(fds[0]); // no read
    // some delay
    char str[] = "Hello FIFO";
    int len = strlen(str);
    nbytes = write(fds[1], str, len);
    // error handling
    close(fds[1]); // done with writing
  }
  return 0;
}
