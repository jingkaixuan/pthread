#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * thread_func(void *args)
{
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		printf("Sub Thread: %d\n", i);
		sleep(1);		
	}

	return (void*)0;
}
int main()
{
	int i = 0;
	pthread_t sub_thread;
	if(pthread_create(&sub_thread, NULL, thread_func, NULL) != 0)
	{
		perror("Create thread failed.");
		return 0;
	}

	for(i = 0; i < 10; i++)
	{
		printf("Main Thread: %d\n", i);
		sleep(1);
	}

	pthread_join(sub_thread, NULL);

	return 0;
}
