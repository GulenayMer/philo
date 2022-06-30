/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:26:48 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/30 22:21:18 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_philo(t_pro *p, t_phil *ph)
{

	if ((get_time() - ph->last_meal) > p->time_to_die)
	{
		// printf("%lld  ", get_time() - ph->last_meal);
		pthread_mutex_lock(&(p->dead));
		p->end = 1;
		p->is_dead = 1;
		print_message(p, ph, DEAD);
		pthread_mutex_unlock(&(p->dead));
		return (1);
	}
	return (0);
}

int	check_if_dead(t_pro *p)
{
	int	i;
	int	ret;

	i = 0;
	while (i < p->n_philos)
	{
		ret = dead_philo(p, &p->philos[i]);
		if (ret == 1)
			return (1);
		i++;
	}
	return (0);
}

/* void	dies_philo_sleep(t_pro *p, t_phil *ph)
{
	long long	current_time;

	current_time = get_time();
		if((current_time - ph->last_meal + p->time_to_sleep) >= p->time_to_die)
		{
			p->is_dead = 1;
			p->end = 1;
	
		}
}
 */
void	sleep_philo(t_pro *p, t_phil *ph)
{
	print_message(p, ph, SLEEP);
	if (!p->end)
		usleep(p->time_to_sleep * 1000);
}

void	think_philo(t_pro *p, t_phil *ph)
{
/* 	if (dead_philo(p, ph))
		return ; */
	print_message(p, ph, THINK);
}
