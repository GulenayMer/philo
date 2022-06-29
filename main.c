/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/29 21:31:10 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_sleep_think(t_pro *p, t_phil *ph)
{
	pthread_mutex_lock(&(p->fork[ph->left_fork]));
	print_message(p, ph, FORK);
	dead_philo(p, ph);
	pthread_mutex_lock(&(p->fork[ph->right_fork]));
	print_message(p, ph, FORK);
	ph->last_meal = get_time();
	print_message(p, ph, EAT);
	usleep(p->time_to_eat * 1000);
	ph->meals_eaten++;
	dead_philo(p, ph);
	pthread_mutex_unlock(&(p->fork[ph->left_fork]));
	pthread_mutex_unlock(&(p->fork[ph->right_fork]));
	sleep_philo(p, ph);
	think_philo(p, ph);
}

/* simulation for each philosopher */
void	*routine(void *philosophers)
{
	t_pro	*p;
	t_phil	*ph;

	ph = (t_phil *)philosophers;
	p = ph->pro;
	printf("current time1: (%lld), p: (%d)\n", get_time() - p->start, ph->id);
	if (p->n_philos == 1)
	{
		usleep(p->time_to_die * 1000);
		print_message(p, ph, DEAD);
		return (0);
	}
 	while (!p->end)
	{
		printf("current time2: (%lld), p: (%d)\n", get_time() - p->start, ph->id);
		if (ph->id % 2 == 0)
			usleep(p->time_to_eat * 1000);
		eat_sleep_think(p, ph);
		if (p->is_dead)
		{
			dead_philo(p, ph);
			break ;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_pro		process;

	if (argc < 2)
		return (1);
	get_args(&process, argv, argc);
	init_data(&process);
	create_tread(&process);
	return (0);
}
