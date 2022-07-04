/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:26:48 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/01 14:17:46 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* for the 'eat routine' */
int	eat_philo(t_pro *p, t_phil *ph)
{
	pthread_mutex_lock(&(p->fork_mutex[ph->left_fork]));
	print_message(p, ph, FORK);
	pthread_mutex_lock(&(p->fork_mutex[ph->right_fork]));
	print_message(p, ph, FORK);
	pthread_mutex_lock(&p->last_meal_mutex);
	ph->time_last_meal = get_time();
	pthread_mutex_unlock(&p->last_meal_mutex);
	print_message(p, ph, EAT);
	p->n_meals++;
	usleep(p->time_to_eat * 1000);
	pthread_mutex_unlock(&(p->fork_mutex[ph->left_fork]));
	pthread_mutex_unlock(&(p->fork_mutex[ph->right_fork]));
	return (0);
}

int	eat_sleep_think(t_pro *p, t_phil *ph)
{
	eat_philo(p, ph);
	p->n_fed++;
	ft_meals(p);
	sleep_philo(p, ph);
	think_philo(p, ph);
	usleep(100);
	return (0);
}

/* */
int		dead_philo(t_pro *p)
{
	while (1)
	{
		pthread_mutex_lock(&p->last_meal_mutex);
		pthread_mutex_lock(&p->dead_mutex);
		if (get_time() - p->philos->time_last_meal > p->time_to_die)
		{
			if (!p->flag_dead)
				print_message(p, p->philos, DEAD);
			p->flag_dead = 1;
			p->end = 1;
			print_message(p, p->philos, DEAD);
			pthread_mutex_unlock(&p->last_meal_mutex);
			pthread_mutex_unlock(&p->dead_mutex);
			return (0);
		}
		pthread_mutex_unlock(&p->last_meal_mutex);
		pthread_mutex_unlock(&p->dead_mutex);
		if (p->flag_dead)
			return (0);
	}
	return (0);
}

/* for the 'sleep routine' */
int	sleep_philo(t_pro *p, t_phil *ph)
{
	print_message(p, ph, SLEEP);
	usleep(p->time_to_sleep * 1000);
	return (0);
}

/* for the 'think routine' */
int	think_philo(t_pro *p, t_phil *ph)
{
	print_message(p, ph, THINK);
	return (0);
}
