/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:39 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/29 21:29:23 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_args(t_pro *process, char **argv, int argc)
{
	process->n_philos = ft_atoi(argv[1]);
	process->time_to_die = ft_atoi(argv[2]);
	process->time_to_eat = ft_atoi(argv[3]);
	process->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		process->n_meals = ft_atoi(argv[5]);
	else
		process->n_meals = -1;
	return (0);
}

void	init_fork(t_pro *process)
{
	int	i;
	int	n;

	n = process->n_philos;
	process->fork = (pthread_mutex_t *)malloc((sizeof(pthread_mutex_t)) * n);
	if (!process->fork)
		return ;
	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_mutex_init(&(process->fork[i]), NULL) != 0)
			printf("error in forks initializing");
		i++;
	}
}

void	init_data(t_pro *process)
{
	int	i;

	process->philos = malloc(sizeof(t_phil) * process->n_philos);
	if (!process->philos)
		return ;
	i = 0;
	while (i < process->n_philos)
	{
		process->philos[i].pro = process;
		process->philos[i].id = i + 1;
		process->philos[i].last_meal = 0;
		process->philos[i].meals_eaten = 0;
		process->philos[i].left_fork = i;
		if (i == process->n_philos - 1)
			process->philos[i].right_fork = 0;
		else
			process->philos[i].right_fork = i + 1;
		i++;
	}
	process->end = 0;
	process->is_dead = 0;
	if (pthread_mutex_init(&(process->print), NULL) != 0)
		printf("error in print initializing");
	if (pthread_mutex_init(&(process->dead), NULL) != 0)
		printf("error in dead initializing");
}

/* pthread_create starts/initiliazes a new thread in the calling process*/
void	create_tread(t_pro *process)
{
	int	i;

	i = 0;
	process->start = get_time();
	while (i < process->n_philos)
	{
		process->philos[i].last_meal = get_time();
		if ((pthread_create(&(process->philos[i].tid), NULL, &routine, \
			&(process->philos[i]))) != 0)
			printf("Error with creating thread\n");
		i++;
	}
	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_join(process->philos[i].tid, NULL) != 0)
			printf("Error with joining thread\n");
		i++;
	}
}
