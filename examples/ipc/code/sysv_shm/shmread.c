#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main() {
  const int SIZE = 4096;
  int shm_fd;
  void *ptr;
  shm_fd = shm_open("shmsimple", O_CREAT | O_RDONLY, 0666);
  if (shm_fd < 0) {
    perror("shm_open");
    exit(1);
  }
  ftruncate(shm_fd, SIZE);
  ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
  if (ptr == MAP_FAILED) {
    printf("Map failed\n");
    return -1;
  }
  char buf[SIZE];
  strcpy(buf, ptr);
  printf("buf=%s\n", buf);
  munmap(ptr, SIZE);
}
