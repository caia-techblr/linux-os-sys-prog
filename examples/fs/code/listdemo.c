#include <dirent.h>
#include <stdio.h>

int main() {
  DIR *dp;
  char *path = "."; // path=argv[1]
  dp = opendir(path);
  if (dp == NULL) {
    fprintf(stderr, "dir open failed\n");
    exit(1);
  }
  struct dirent *ps;
  while (1) {
    ps = readdir(dp);
    if (ps == NULL)
      break;
    printf("%s\n", ps->d_name);
  }
  closedir(dp);
  return 0;
}
