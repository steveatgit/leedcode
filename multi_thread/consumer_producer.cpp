#include<pthread.h>
#include<unistd.h>
#include<stack>
#include<stdio.h>
using namespace std;

stack<int> st;
pthread_mutex_t mutex;

void *consumer(void *ptr)
{
	while(1) {
		pthread_mutex_lock(&mutex);
		if(!st.empty()) {
			printf("consume: %d\n", st.top());
			st.pop();
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return 0;
}

void* producer(void *ptr)
{
	while(1) {
		pthread_mutex_lock(&mutex);
		st.push(st.size());
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return 0;
}

int main()
{
	pthread_t consumer_id;
	pthread_t producer_id;
	pthread_mutex_init(&mutex, NULL);
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
