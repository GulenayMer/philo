/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:05:07 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/06 18:54:34 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* number of meals */
//void	ft_meals(t_pro *p, int *meals_eaten)
void	ft_meals(t_pro *p, t_phil *ph)
{
	if (p->flag_meal == 1 && (ph->meals_eaten == p->n_meals))
	{
		pthread_mutex_lock(&p->dead_mutex);
		++p->n_fed;
		if (p->flag_meal == 1 && p->n_fed == p->n_philos)
		{
			if (!(p->flag_dead))
			{
				pthread_mutex_lock(&p->print_mutex);
				printf("All have eaten as much as number of meals\n");
				p->end = 1;
				pthread_mutex_unlock(&p->print_mutex);
			}
			pthread_mutex_lock(&p->end_mutex);
			p->flag_dead = 1;
			pthread_mutex_unlock(&p->end_mutex);
		}
		pthread_mutex_unlock(&p->dead_mutex);
	}
}

int	one_philo(t_pro *p, t_phil *ph)
{
	if (p->n_philos == 1)
	{
		usleep(p->time_to_die * 1000);
		print_message(p, ph, DEAD);
		return (1);
	}
	return (0);
}

/* simulation for each philosopher */
void	*routine(void *philosophers)
{
	t_pro	*p;
	t_phil	*ph;

	ph = (t_phil *)philosophers;
	p = ph->pro;
	if (one_philo(p, ph))
		return (0);
	if (ph->id % 2 == 0)
		usleep(p->time_to_eat * 1000);
	pthread_mutex_lock(&p->last_meal_mutex);
	ph->time_last_meal = get_time();
	pthread_mutex_unlock(&p->last_meal_mutex);
	while (1)
	{	
		eat_sleep_think(p, ph);
		pthread_mutex_lock(&p->dead_mutex);
		if (p->flag_dead)
		{
			pthread_mutex_unlock(&p->dead_mutex);
			return (0);
		}
		pthread_mutex_unlock(&p->dead_mutex);
	}
	return (0);
}
