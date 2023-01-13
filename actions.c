/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:26:48 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/06 18:16:38 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_sleep_think(t_pro *p, t_phil *ph)
{
	eat_philo(p, ph);
	sleep_philo(p, ph);
	think_philo(p, ph);
	usleep(100);
}

/* for the 'eat routine' */
void	eat_philo(t_pro *p, t_phil *ph)
{
	pthread_mutex_lock(&(p->fork_mutex[ph->left_fork]));
	print_message(p, ph, FORK);
	pthread_mutex_lock(&(p->fork_mutex[ph->right_fork]));
	print_message(p, ph, FORK);
	pthread_mutex_lock(&p->last_meal_mutex);
	ph->time_last_meal = get_time();
	pthread_mutex_unlock(&p->last_meal_mutex);
	print_message(p, ph, EAT);
	ph->meals_eaten++;
	ft_meals(p, ph);
	usleep(p->time_to_eat * 1000);
	pthread_mutex_unlock(&(p->fork_mutex[ph->left_fork]));
	pthread_mutex_unlock(&(p->fork_mutex[ph->right_fork]));
}

/* for the 'sleep routine' */
void	sleep_philo(t_pro *p, t_phil *ph)
{
	print_message(p, ph, SLEEP);
	usleep(p->time_to_sleep * 1000);
}

void	dead_philo2(t_pro *p)
{
	p->flag_dead = 1;
	pthread_mutex_lock(&p->end_mutex);
	p->end = 1;
	pthread_mutex_unlock(&p->end_mutex);
	print_message(p, p->philos, DEAD);
	pthread_mutex_unlock(&p->dead_mutex);
	pthread_mutex_unlock(&p->last_meal_mutex);
}

/* check if dead */
int	dead_philo(t_pro *p)
{
	while (1)
	{
		pthread_mutex_lock(&p->last_meal_mutex);
		pthread_mutex_lock(&p->dead_mutex);
		if (get_time() - p->philos->time_last_meal > p->time_to_die)
		{
			if (!p->flag_dead)
				print_message(p, p->philos, DEAD);
			dead_philo2(p);
			return (0);
		}
		pthread_mutex_unlock(&p->last_meal_mutex);
		pthread_mutex_unlock(&p->dead_mutex);
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
