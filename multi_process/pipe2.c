#include<stdio.h>  
#include<unistd.h>  
#include<sys/types.h>  
#include<errno.h>  
char readbuf[100];  
char writebuf[100];  
int main()  
{
	int fd[2];
	pid_t pid;
    if(pipe(fd) < 0) {
		printf("create pipe error\n");
	}
	if((pid = fork()) < 0) {
		printf("fork error");
		exit(-1);
	}
	if(0 == pid) { // child process
		close(fd[0]);
		strcpy(writebuf, "hello world");
		int num = write(fd[1], writebuf, strlen(writebuf));
		printf("child write %d bytes\n", num);
		close(fd[1]);
		printf("child close fd[1]\n");
//		sleep(10);  // wait father to read data
	} else if (pid>0) {
		close(fd[1]);
		sleep(3);  //wait to make sure child process write data
		int num = read(fd[0], readbuf, sizeof(readbuf));
		printf("read data: %s\n", readbuf);
		close(fd[0]);
		exit(1);
	}
	return 1;
}
	
