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

int	main()
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	printf("Seconds : %ld\n", current_time.tv_sec);
	return (0);
}
