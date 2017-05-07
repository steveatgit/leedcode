#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main()
{
    time_t start,stop;
    start = time(NULL);
    usleep(1000000);//dosomething   microsecond
    stop = time(NULL);
    printf("Use Time:%ld\n",(stop-start));   //1
	 return 0;
}
