/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:05:07 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/01 14:07:55 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (ph->id % 2 == 0)
			usleep(p->time_to_eat * 1000);
	pthread_mutex_lock(&p->last_meal_mutex);
	ph->time_last_meal = get_time();
	pthread_mutex_unlock(&p->last_meal_mutex);
	while (!p->end)
	{
		dead_philo(p);
/* 		if (p->end)
		{
			pthread_mutex_lock(&p->dead_mutex);
			p->end = 1;
			pthread_mutex_unlock(&p->dead_mutex);
			break ;
		} */
		eat_sleep_think(p, ph);
	}
	return (NULL);
}