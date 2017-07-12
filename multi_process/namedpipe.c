#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
char buf[100];
#define PATH "test_fifo"
int main()
{
	int fd;
	unlink(PATH);
	mkfifo(PATH, 0777);
	if(fork()==0) { //child process
		char s[] = "hello world";
		fd = open(PATH, O_WRONLY);
		write(fd, s, strlen(s));
	} else {
		fd = open(PATH, O_RDONLY);
		read(fd, buf, sizeof(buf));
		printf("read data: %s\n", buf);
	}
	return 0;
}
