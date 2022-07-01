/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/01 14:17:03 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(t_pro *p, t_phil *ph)
{
	pthread_mutex_lock(&(p->fork[ph->left_fork]));
	print_message(p, ph, FORK);
	pthread_mutex_lock(&(p->fork[ph->right_fork]));
	print_message(p, ph, FORK);
}

int	eat_sleep_think(t_pro *p, t_phil *ph)
{
	int	ret;
	
	if (p->end)
		return (1);
	ph->last_meal = get_time();
	get_forks(p, ph);
	print_message(p, ph, EAT);
	//usleep(p->time_to_eat * 1000);

	usleep(10);
 	while ((get_time() - ph->last_meal) < p->time_to_eat)
	{
		ret = dead_philo(p, ph);
		if (ret == 1)
		{
			// printf("%lld  ", get_time() - ph->last_meal);
			// printf("%d  ", p->time_to_eat);
			return (1);
		}
	}
	ph->meals_eaten++;
	pthread_mutex_unlock(&(p->fork[ph->left_fork]));
	pthread_mutex_unlock(&(p->fork[ph->right_fork]));
	sleep_philo(p, ph);
	think_philo(p, ph);
	return (0);
}

/* simulation for each philosopher */
void	*routine(void *philosophers)
{
	t_pro	*p;
	t_phil	*ph;

	ph = (t_phil *)philosophers;
	p = ph->pro;
	if (p->n_philos == 1)
	{
		usleep(p->time_to_die * 1000);
		print_message(p, ph, DEAD);
		return (0);
	}
	while (!p->end)
	{
		if (ph->id % 2 == 0)
			usleep(p->time_to_eat * 1000);
		eat_sleep_think(p, ph);
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
