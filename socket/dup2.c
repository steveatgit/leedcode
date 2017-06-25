//http://blog.csdn.net/u011641885/article/details/48244893
#include<stdio.h>
#include<fcntl.h>  // for open()

int main()
{
	int fd = open("test", O_RDWR | O_CREAT, 0644);
	dup2(fd, 1);  // 重定向fd到1，1表示STDOUT
	close(fd);
	printf("print to test file");
	return 0;
} 
