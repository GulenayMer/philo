/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:39 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/24 23:47:04 by mgulenay         ###   ########.fr       */
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

void	init_all(t_pro *process)
{
	int	i;

	process->philos = malloc(sizeof(t_phil) * process->n_philos);
	i = 0;
	while (i < process->n_philos)
	{
		process->philos[i].id = i;
		process->philos[i].left_fork = i;
		process->start_time = get_time();
		process->philos->last_meal = 0;
		if (i == process->n_philos - 1)
			process->philos[i].right_fork = 0;
		else
			process->philos[i].right_fork = i + 1;
		i++;
	}
	fork_init(process);
}

void	fork_init(t_pro *process)
{
	int	i;

	process->fork = (pthread_mutex_t *)malloc((sizeof(pthread_mutex_t)) * process->n_philos);
	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_mutex_init(&process->fork[i], NULL) != 0)
			printf("error in forks initializing");
		else
			printf("forks");
			printf("%p\n",&process->fork[i]);
		i++;
	}
}
