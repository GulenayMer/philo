/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:39 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/01 14:07:36 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* getting arguments as argv, and storing them into the variables respectively */
int	get_args(t_pro *process, char **argv, int argc)
{
	process->n_philos = ft_atoi(argv[1]);
	process->time_to_die = ft_atoi(argv[2]);
	process->time_to_eat = ft_atoi(argv[3]);
	process->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		process->n_meals = ft_atoi(argv[5]);
	}
	else
		process->n_meals = -1;
	return (0);
}

/* initiliazing the variables */
int	init_data_for_philos(t_pro *process)
{
	int	i;

	process->philos = malloc(sizeof(t_phil) * process->n_philos);
	if (!process->philos)
		return (1);
	i = 0;
	while (i < process->n_philos)
	{
		process->philos[i].pro = process;
		process->philos[i].id = i + 1;
		process->philos[i].meals_eaten = 0;
		process->philos[i].left_fork = i;
		if (i == process->n_philos - 1)
			process->philos[i].right_fork = 0;
		else
			process->philos[i].right_fork = i + 1;
		i++;
	}
	return (0);
}

/* initiliazing the other mutexes */
int	ft_init_mutex(t_pro *process)
{
	ft_init_fork(process);
	if (pthread_mutex_init(&(process->print_mutex), NULL) != 0)
	{
		printf("error in print initializing");
		return (1);
	}
	if (pthread_mutex_init(&(process->last_meal_mutex), NULL) != 0)
	{
		printf("error in last meal initializing");
		return (1);
	}
	if (pthread_mutex_init(&(process->dead_mutex), NULL) != 0)
	{
		printf("error in dead mutex initializing");
		return (1);
	}
	return (0);
}

/* initiliazing the forks mutextes for each philos, as the number of philo = the number of forks */
int	ft_init_fork(t_pro *process)
{
	int	i;
	int	n;

	n = process->n_philos;
	process->fork_mutex = (pthread_mutex_t *)malloc((sizeof(pthread_mutex_t)) * n);
	if (!process->fork_mutex)	
		return (1);
	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_mutex_init(&(process->fork_mutex[i]), NULL) != 0)
		{
			printf("error in forks initializing");
			return (1);
		}
		i++;
	}
	return (0);
}
