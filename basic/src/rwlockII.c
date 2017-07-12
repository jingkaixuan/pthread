#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ_THREAD_COUNT 10
#define WRITE_THREAD_COUNT 5

pthread_rwlock_t lock;

void * func_read()
{
	pthread_rwlock_rdlock(&lock);
	printf("Read\n");
	usleep(200000);
	pthread_rwlock_unlock(&lock);
	return (void*)0;
}

void * func_write()
{
	pthread_rwlock_wrlock(&lock);
	printf("Write\n");
	usleep(200000);
	pthread_rwlock_unlock(&lock);
	return (void*)0;
}


int main()
{
	int i;
	pthread_t t1[READ_THREAD_COUNT], t2[WRITE_THREAD_COUNT];

	pthread_rwlock_init(&lock, NULL);

	for(i = 0; i < READ_THREAD_COUNT; ++i)
	{
		pthread_create(&t1[i], NULL, func_read, NULL);
	}

	for(i = 0; i < WRITE_THREAD_COUNT; ++i)
	{
		pthread_create(&t2[i], NULL, func_write, NULL);
	}

	for(i = 0; i < 5; ++i)
	{
		pthread_join(t1[i], NULL);
		pthread_join(t2[i], NULL);
	}
}
