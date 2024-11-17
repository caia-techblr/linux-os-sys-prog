/* Anonymous mapping */
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

void handler_int(int signo) { printf("SIGINT received\n"); }

// ps -e -o pid,ppid,vsz,rsz,maj_flr,min_flt,cmd | grep a.out
int main() {
  printf("welcome---pid=%d\n", getpid());
  const int MAPSIZE = 32 * sysconf(_SC_PAGE_SIZE);
  void *pbase;
  pid_t ret; // int ret;
  int i, fd, val;
  fd = -1;
  signal(SIGINT, handler_int);
  printf("going to map some memory\n");
  pause(); // pause/sigsuspend/sleep
  pbase = mmap(0, MAPSIZE, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS,
               fd, 0);
  if (pbase == MAP_FAILED) {
    printf("Map failed\n");
    return -1;
  }
  printf("going to access pages\n");
  pause();
  char *ptr = pbase;
  for (i = 0; i < 32; i++) {
    *ptr = rand() % 100;
    val = *ptr;
    //*ptr=rand()%100;val=*ptr;
    // ptr+=4096;
    sleep(1); // 500ms
    msync(ptr, 4096, MS_SYNC);
    ptr += 4096;
  }
  printf("going to unmap memory\n");
  pause();
  munmap(pbase, MAPSIZE);
  printf("going to exit\n");
  pause();
  return 0; // exit(0);
}
