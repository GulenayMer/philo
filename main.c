/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/27 18:00:00 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* pthread_create starts a new thread in the calling process */
/* create 10 threads, each taking a unique prime form the primes array
 and print it on the screen. */

int	init_args(t_philos *process, int argc, char **argv)
{
	process->n_philos = ft_atoi(argv[1]);
	//process->time_to_die = ft_atoi(argv[2]);
	//process->time_to_eat = ft_atoi(argv[3]);
	//process->time_to_sleep = ft_atoi(argv[4]);
	//if (argc == 6)
	//	process->n_meals = ft_atoi(argv[5]);
	//else
	//	process->n_meals = -1;
	return (0);
}

long int	philosophers(t_philos *process, pthread_t *threads)
{
	int	i;
	t_philos *philosophers;
	
	//philosophers = malloc(sizeof(t_philos *) * process->n_philos);
	i = 0;
	while (i < process->n_philos)
	{
		//threads[i] = philosophers[i];
		if (pthread_create(&threads[i], NULL, &routine, philosophers) != 0)
			return (3);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philos process; // struct
	struct timeval tvalue;
	pthread_t *threads = NULL; // my threads
	process.n_philos = 0;
	gettimeofday(&tvalue, 0);
	if (argc < 5)
		return (1);
	threads = malloc(sizeof(t_philos) * process.n_philos);
	if (!threads)
		return (2);
	init_args(&process, argv);
	philosophers(&process, threads);
	return (0);
}





/*
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
}*/
