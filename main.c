/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/23 18:04:38 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <pthread.h>

long long	get_time(void)
{
	struct timeval	time;
	long long		t_ms;
	long long		current_time;
	int 			start = 30;

	gettimeofday(&time, NULL);
	t_ms = (time.tv_sec * 1000 + time.tv_usec / 1000);
	current_time = t_ms - start;
	return (current_time);
}

int	get_args(t_pro *process, char **argv)
{
	process->n_philos = ft_atoi(argv[1]);
	/*
	process->time_to_die = ft_atoi(argv[2]);
	process->time_to_eat = ft_atoi(argv[3]);
	process->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		process->n_meals = ft_atoi(argv[5]);
	else
		process->n_meals = -1;
	*/
	//printf("%d", process->n_philos);
	return (0);
} 

void fork_init(t_pro *process)
{
	int	i;

	process->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * process->n_philos);
	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_mutex_init(&process->fork[i], NULL) == 0)
			printf("I do not know!");
		i++;
	}


}

void	*routine()
{
	printf("eating\n");
	return(0);
}

/* pthread_create starts/initiliazes a new thread in the calling process*/
long int	philosophers(t_pro *process)
{
	int			i;

	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_create(&process->philos[i].tid, NULL, &routine,
			(void *)&process->philos[i]) != 0)
			return (3);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(process->philos[i].tid, NULL) != 0)
			return (4);
		i++;
	}
	return (0);
}

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
	fork_init(&process);
	get_time();
	return (0);
}
