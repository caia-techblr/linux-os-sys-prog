#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

const int max=10;

sem_t sm;
sem_t sorder;

void* task_body1(void* pv)          //producer
{
	int i;
	printf("A--welcome\n");
    sleep(5);
    sem_wait(&sm);
	for(i=1;i<=max;i++)
	{
		printf("A--%d\n",i);
		sleep(1);
	}
    sem_post(&sm);
    sem_post(&sorder);              //unlock
	//pthread_exit(NULL);
}
void* task_body2(void* pv)          //consumer
{
	int i;
	printf("B--welcome\n");
    sem_wait(&sorder);              //lock
    sem_wait(&sm);
	for(i=1;i<=max;i++)
	{
		printf("B--%d\n",i);
		sleep(1);
	}
    sem_post(&sm);
	//pthread_exit(NULL);
}
int main()
{
	pthread_t pt1,pt2;	
    sem_init(&sm,0,1);              //init-1, mutual exclusion
    sem_init(&sorder, 0, 0);        //init-0, sequencing
	pthread_create(&pt1,NULL,task_body1,NULL);
	pthread_create(&pt2,NULL,task_body2,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
    sem_destroy(&sm);
    sem_destroy(&sorder);
	printf("main--thank you\n");
	return 0;	//exit(0);
}

