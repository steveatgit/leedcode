#include<pthread.h>
#include<unistd.h>  //sleep(1) head file
#include<stack>
#include<stdio.h>
#include<iostream>
using namespace std;

stack<int> st;
pthread_mutex_t mtx;  //not use mutex, or it will be ambiguous

void *consumer(void *ptr)
{
	while(1) {
		pthread_mutex_lock(&mtx);
		if(!st.empty()) {
			printf("consumer size is: %d\n", st.top());
			st.pop();
		}
		pthread_mutex_unlock(&mtx);
		sleep(1);
	}
	return 0;
}

void* producer(void *ptr)
{
	while(1) {
		pthread_mutex_lock(&mtx);
		st.push(st.size());
		cout<<"producer size is: "<<st.size()<<endl;
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
	pthread_join(producer_id, NULL);
	pthread_join(consumer_id, NULL);
	return 0;
}
