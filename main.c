/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/26 21:09:43 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine1()
{
	printf("Test\n");
	sleep(1);
	printf("ending\n");
	sleep(1);
	return (0);
}

/*void *routine2()
{
	printf("ending\n");
	sleep(1);
	return(0);
}*/

/* pthread_create starts a new thread in the calling process */
/*int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	if (pthread_create(&thread1, NULL, routine1, NULL) != 0)
		return (1);
	if (pthread_create(&thread2, NULL, routine1, NULL) != 0)
		return (2);
	if (pthread_join(thread1, NULL) != 0)
		return (3);
	if (pthread_join(thread2, NULL) != 0)
		return (4);
	return (0);
}*/

/* create 10 threads, each taking a unique prime form the primes array
 and print it on the screen. */

void	*routine(void *arg)
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
}
