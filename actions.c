/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:26:48 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/29 21:25:22 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_philo(t_pro *p, t_phil *ph)
{
	long long	current_time;
	
	current_time = get_time();
	if (current_time - ph->last_meal >= p->time_to_die)
	{
		p->end = 1;
		p->is_dead = 1;
		pthread_mutex_lock(&(p->dead));
		print_message(p, ph, DEAD);
		pthread_mutex_unlock(&(p->dead));
		return (1);
	}
	return (0);
}

void	dies_philo_sleep(t_pro *p, t_phil *ph)
{
	long long	current_time;

	current_time = get_time();
	if((current_time - ph->last_meal + p->time_to_sleep) >= p->time_to_die
		&& !p->end)
		dead_philo(p, ph);
}

void	sleep_philo(t_pro *p, t_phil *ph)
{
	if (dead_philo(p, ph))
		return ;
	print_message(p, ph, SLEEP);
	dies_philo_sleep(p, ph);
	if (!p->end)
		usleep(p->time_to_sleep * 1000);
}

void	think_philo(t_pro *p, t_phil *ph)
{
	if (dead_philo(p, ph))
		return ;
	print_message(p, ph, THINK);
}
