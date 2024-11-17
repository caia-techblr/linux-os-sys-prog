#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main() {
  const int SIZE = 4096;
  int shm_fd;
  void *ptr;
  shm_fd = shm_open("shmsimple", O_CREAT | O_RDWR, 0666);
  if (shm_fd < 0) {
    perror("shm_open");
    exit(1);
  }
  ftruncate(shm_fd, SIZE);
  ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  if (ptr == MAP_FAILED) {
    printf("Map failed\n");
    return -1;
  }
  strcpy(ptr, "Hello Shared Memory");
  munmap(ptr, SIZE);
  // shm_unlink
}
