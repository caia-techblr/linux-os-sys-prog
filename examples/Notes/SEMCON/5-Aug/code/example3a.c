/* File Mapping */
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int filesz=4096; //find the length and round
			 		 //to multiples of 4096
	int fd,offset=0;
	fd=open("sample.txt",O_RDWR|O_CREAT,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
    ftruncate(fd,filesz);
	void *pbase;
	pbase=mmap(0,filesz, PROT_WRITE|PROT_READ, MAP_PRIVATE, fd,offset);
	if(pbase==MAP_FAILED)
	{
		fprintf(stderr,"mapping failed\n");
		//close(fd);
		exit(1);
	}
    char buf[64];
    //char str[]="ABCDEFGHIJKLMNOPQRSTUWXYZ";
    //strncpy(pbase,str,26);
	strncpy(buf,pbase,10);	//for loop
    buf[10]='\0';
	printf("buf=%s\n",buf);
	strcpy(buf,pbase+10);
	printf("buf=%s\n",buf);
    //msync(pbase,26,MS_SYNC);
    //sync();
	munmap(pbase,filesz);
    //int nbytes=read(fd,buf,64);
    //write(1,buf,nbytes);
	close(fd);
	return 0;
}
		









