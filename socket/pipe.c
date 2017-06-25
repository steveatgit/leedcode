// http://blog.csdn.net/thinkinwm/article/details/8710857
#include<stdio.h>

int main()
{
	int fd[2], ret;
	char write_buf[30], read_buf[30];
	pipe(fd);
	while((ret = fork()) == -1);
	if (0 == ret) { // child process
		sprintf(write_buf, "this is a pipe example\n");
		write(fd[1], write_buf, sizeof(write_buf));
		exit(0);
	} else {
		wait(0);  // wait for child exit
		read(fd[0], read_buf, sizeof(read_buf));
		printf("%s", read_buf);
	}
	return 0;
}	
