// http://www.cnblogs.com/youtherhome/archive/2013/03/17/2964195.html
// 程序运行有点小问题，时序上还是不太对
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define MAXSTACK 100
int stack[MAXSTACK][2];
sem_t sem;
int size = 0;

void* readData1(void* ptr)
{
	FILE *fp = fopen("1.dat", "r");
	while(!feof(fp)) {
		sleep(1);
		fscanf(fp, "%d %d", &stack[size][0], &stack[size][1]);
		sem_post(&sem);
		++size;
	}
	fclose(fp);
	return 0;
}

void *readData2(void *ptr)
{
	FILE *fp = fopen("2.dat", "r");
	while(!feof(fp)) {
		fscanf(fp, "%d %d", &stack[size][0], &stack[size][1]);
		sem_post(&sem);
		++size;
	}
	fclose(fp);
	return 0;
}

void *handleData1(void *ptr) 
{
	while(1) {
		sleep(1);
		sem_wait(&sem);
		printf("Plus:%d+%d=%d\n", stack[size][0], stack[size][1], stack[size][0]+stack[size][1]);
		--size;
	}
	return 0;
}

void* handleData2(void *ptr)
{
	while(1) {
		sem_wait(&sem);
		printf("Multiply:%d+%d=%d\n", stack[size][0], stack[size][1], stack[size][0]*stack[size][1]);
		size--;
	}
	return 0;
}

int main()
{
	pthread_t t1, t2, t3, t4;
	sem_init(&sem, 0, 0);
	pthread_create(&t1, NULL, handleData1, NULL);
//	pthread_create(&t2, NULL, handleData2, NULL);
	pthread_create(&t3, NULL, readData1, NULL);
	//pthread_create(&t4, NULL, (void *)readData2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t3, NULL);
}
			
