/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:26:48 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/28 23:08:41 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead_philo(t_pro *p, t_phil *ph)
{
	long long	current_time;

	current_time = get_time();
	pthread_mutex_init(&(p->dead), NULL);
	if ((current_time - ph->last_meal) >= p->time_to_die)
	{
		pthread_mutex_lock(&(p->dead));
		print_message(p, ph, DEAD);
		p->end = 1;
		pthread_mutex_unlock(&(p->dead));
	}
}

void	sleep_philo(t_pro *p, t_phil *ph)
{
	print_message(p, ph, SLEEP);
	usleep(p->time_to_sleep * 1000);
}

void	think_philo(t_pro *p, t_phil *ph)
{
	print_message(p, ph, THINK);
}
