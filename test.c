#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

/*void	*routine(void *arg)
{
	int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int	index;

	index = *(int *)arg;
	printf("%d\n", primes[index]);
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	th[10];
	int			i;
	int			*a;

	i = 0;
	while (i < 10)
	{		
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			write(1, "Failed to create thread\n", 25);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(th[i], NULL) != 0)
			write(1, "Failed to join\n", 16);
		i++;
	}
	return (0);
}*/

 long long get_time()
{
	struct timeval time;
	long long t_ms;

	gettimeofday(&time, NULL);
	t_ms = (time.tv_sec * 1000 + time.tv_usec / 1000); // convert seconds and microseconds to miliseconds
	return (t_ms);
}

int	main()
{

	long long i;
	i = get_time();
	printf("%lld", i);
	return (0);
}

//printf("Seconds: %ld\n", time.tv_sec);
//	printf("Seconds in miliseconds : %ld\n", time.tv_sec * 1000);
//	printf("Microseconds : %d\n", time.tv_usec);
//	printf("Microseconds in miliseconds : %d\n", time.tv_usec / 1000);