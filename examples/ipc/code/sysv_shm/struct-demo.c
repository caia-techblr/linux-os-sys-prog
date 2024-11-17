#include <sys/shm.h>
#include <unistd.h>

#define KEY 1235

struct student {
  int rollno;
  char name[20];
  double total;
};

int main() {
  int ret, shmid, st;
  shmid = shmget(KEY, 100 * sizeof(struct student),
                 IPC_CREAT | 0666); // just before fork
  struct student *ps;
  // ps=shmat(shmid,0,0); //once also enough
  ret = fork();
  if (ret == 0) { // read
    ps = shmat(shmid, 0, 0);
    printf("child:rollno=%d,"
           "name=%s,marks=%lf\n",
           ps->rollno, ps->name, ps->total);
    shmdt(ps);
  } else // write
  {
    ps = shmat(shmid, 0, 0);
    // sleep(1);
    // ps->rollno=1201;
    printf("enter roll no.\n");
    scanf("%d", &ps->rollno);
    strcpy(ps->name, "abcd");
    ps->total = 94.25;
    shmdt(ps);
    waitpid(-1, &st, 0);
    shmctl(shmid, IPC_RMID, NULL);
  }
  return 0;
}
