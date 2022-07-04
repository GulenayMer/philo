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

/* number of meals */
int	ft_meals(t_pro *p)
{
	pthread_mutex_lock(&p->dead_mutex);
	if (p->flag_meal && p->philos->meals_eaten == p->n_meals)
	{
			//if (c == p->n_philos)
			//{
				if (!(p->flag_dead))
					printf("All ate\n");
				p->philos->full = 1;
				p->end = 1;
				return (1);
			//}
	}
	pthread_mutex_unlock(&p->dead_mutex);
	return (0);
}	

/* simulation for each philosopher */
void	*routine(void *philosophers)
{
	t_pro	*p;
	t_phil	*ph;
	//pthread_t	control_die;

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
	while (1)
	{
		eat_sleep_think(p, ph);
		if (p->flag_dead)
		{
			pthread_mutex_lock(&p->dead_mutex);
			pthread_mutex_unlock(&p->dead_mutex);
			return (0);
		}
	}
	return (NULL);
}
