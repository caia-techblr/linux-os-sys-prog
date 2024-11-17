#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

const int max=200;

void* do_work1(void* pv) {
   int i;
   printf("Thread A -- Welcome\n");
   for(i=1;i<=max;i++)
	printf("A--%d\n",i);
}
void* do_work2(void* pv) {
   int i;
   printf("Thread B -- Welcome\n");
   for(i=1;i<=max;i++)
	printf("B--%d\n",i);
}

int main() {
  pthread_t pt1; 
  pthread_t pt2;
  pthread_create(&pt1, NULL, do_work1, NULL);
  pthread_create(&pt2, NULL, do_work2, NULL);
  
  pthread_join(pt1,NULL);
  pthread_join(pt2,NULL);
  printf("main--Thank you\n");
  return 0;     //exit(0);
}


