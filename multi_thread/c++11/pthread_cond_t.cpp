//http://blog.sina.com.cn/s/blog_6ffd3b5c0100mc3n.html
//运行有点问题，好像死锁了，需要调试
#include<pthread.h>
#include<unistd.h>  //sleep(1) head file
#include<stack>
#include<stdio.h>
#include<iostream>
using namespace std;

pthread_mutex_t mtx;  //not use mutex, or it will be ambiguous
pthread_cond_t cnt_nonzero;
unsigned int cnt = 0;

void *consumer(void *ptr)
{
	while(1) {
		pthread_mutex_lock(&mtx);
		while(cnt == 0) {
			pthread_cond_wait(&cnt_nonzero, &mtx);
		}
		cnt--;	
		cout<<"consumer size is: "<<cnt<<endl;
		pthread_mutex_unlock(&mtx);
		sleep(1);
	}
	return 0;
}

void* producer(void *ptr)
{
	while(1) {
		pthread_mutex_lock(&mtx);
		if(cnt == 0) {
			pthread_cond_signal(&cnt_nonzero);
		}
		cnt++;
		cout<<"producer size is: "<<cnt<<endl;
		pthread_mutex_unlock(&mtx);
		sleep(1);
	}
	return 0;
}

int main()
{
	pthread_t consumer_id;
	pthread_t producer_id;
	pthread_mutex_init(&mtx, NULL);
   int ret = pthread_create(&consumer_id, NULL, consumer, NULL);
	if(ret) {
		printf("Fail to create consumer thread");
	}
	ret = pthread_create(&producer_id, NULL, producer, NULL);
	if(ret) {
		printf("Fail to create consumer thread");
	}
	pthread_join(consumer_id, NULL);
	pthread_join(producer_id, NULL);
	return 0;
}
