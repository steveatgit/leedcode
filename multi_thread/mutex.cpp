// http://www.cnblogs.com/youtherhome/archive/2013/03/17/2964195.html

char buffer;
int buf_has_item = 0;
pthread_mutex_t mutex;

void reader_function(void)
{
	while(1) {
		pthread_mutex_lock(&mutex);
		if(buf_has_item == 1) {
			consume(buffer);
			buf_has_item = 0;
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

void writer_function(void)
{
	while(1) {
		pthread_mutex_lock(&mutex);
		if(buf_has_item == 0) {
			buffer = make_new_item();
			buf_has_item = 1;
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

int main()
{
	pthread_t id;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&id, NULL, (void *)&reader_function, NULL);
	writer_function();
	return 0;
}
	
