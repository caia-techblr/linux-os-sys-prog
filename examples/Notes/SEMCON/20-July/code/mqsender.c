#include<mqueue.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int ret;
    mqd_t mqid;
	struct mq_attr attr;
    attr.mq_msgsize=512;
	attr.mq_maxmsg=10;
    mqid=mq_open("/mque3",O_WRONLY|O_CREAT,0666,&attr);
	//mqid=mq_open("/mque3",O_WRONLY|O_CREAT,0666,NULL);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char str[]="Hello Message queue";
	int len=strlen(str);
	ret=mq_send(mqid,str,len,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid);
	return 0;
}


