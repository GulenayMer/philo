/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/08 17:54:28 by mgulenay         ###   ########.fr       */
=======
/*   Updated: 2022/06/07 23:24:40 by mgulenay         ###   ########.fr       */
>>>>>>> 1a4486a02717d359f028e3b79e239facbe0fc37c
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <pthread.h>

<<<<<<< HEAD
int	get_args(t_pro *process, char **argv)
{
	process->n_philos = ft_atoi(argv[1]);
	/*process->time_to_die = ft_atoi(argv[2]);
	process->time_to_eat = ft_atoi(argv[3]);
	process->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		process->n_meals = ft_atoi(argv[5]);
	else
		process->n_meals = -1;*/
	//printf("%d", process->n_philos);
	return (0);
}

void	*routine()
{
	printf("eating\n");
	return (0);
}

/* pthread_create starts/initiliazes a new thread in the calling process*/
long int	philosophers(t_pro *process)
=======
/*void *routine1()
{
	printf("Test\n");
	sleep(1);
	printf("ending\n");
	sleep(1);
	return (0);
}

void *routine2()
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

int	main()
>>>>>>> 1a4486a02717d359f028e3b79e239facbe0fc37c
{
	pthread_t	th[10];
	int			i;
<<<<<<< HEAD

	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_create(&process->philos[i].tid, NULL, &routine, 
			(void *)&process->philos[i]) != 0)
			return (3);
=======
	int			*a;

	i = 0;
	while (i < 10)
	{		
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			write(1, "Failed to  create thread\n", 25);
>>>>>>> 1a4486a02717d359f028e3b79e239facbe0fc37c
		i++;
	}
	i = 0;
	while (i < 10)
	{
<<<<<<< HEAD
		if (pthread_join(process->philos[i].tid, NULL) != 0)
			return (4);
=======
		if (pthread_join(th[i], NULL) != 0)
			write(1, "Failed to join\n", 16);
>>>>>>> 1a4486a02717d359f028e3b79e239facbe0fc37c
		i++;
	}
	return (0);
}
<<<<<<< HEAD

int	main(int argc, char **argv)
{
	t_pro		process;

	if (argc < 2)
		return (1);
	process.philos = malloc(sizeof(t_phil) * process.n_philos);
	if (!process.philos)
		return (2);
	get_args(&process, argv);
	philosophers(&process);
	return (0);
}
=======
>>>>>>> 1a4486a02717d359f028e3b79e239facbe0fc37c
