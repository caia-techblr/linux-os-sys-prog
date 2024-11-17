#include <sys/stat.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int ret;
  char *path = "hello";
  struct stat s1;
  ret = lstat(path, &s1);
  if (ret < 0) {
    perror("lstat");
    exit(1);
  }
  printf("file name\t:%s\n", path);
  printf("inode no.\t:%d\n", s1.st_ino);
  printf("user id\t:%d\n", s1.st_uid);
  printf("group id\t:%d\n", s1.st_gid);
  printf("file size\t:%d\n", s1.st_size);
  printf("last mod time\t:%s\n", ctime(&s1.st_mtime));
  printf("perms\t:%o\n", s1.st_mode & 0777);
  if (S_ISREG(s1.st_mode))
    printf("is a regular file\n");
  else if (S_ISDIR(s1.st_mode))
    printf("is a dir file\n");
  else if (S_ISLNK(s1.st_mode))
    printf("is a sym link\n");
  else // S_ISFIFO, S_ISCHR, S_ISBLK
    printf("unknown/spl file\n");
  return 0;
}
