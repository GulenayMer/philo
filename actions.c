/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:26:48 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/26 16:13:10 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead_philo(t_pro *p, t_phil *ph)
{
	//long long	current_time;
	//current_time = get_time();
	pthread_mutex_init(&(p->dead), NULL);
	pthread_mutex_lock(&(p->dead));
	print_message(p, ph, DEAD);
	pthread_mutex_unlock(&(p->dead));
}

void	sleep_philo(t_pro *p, t_phil *ph)
{
	//long long	current_time;
	//current_time = get_time();
	pthread_mutex_init(&(p->sleep), NULL);
	pthread_mutex_lock(&(p->sleep));
	print_message(p, ph, SLEEP);
	pthread_mutex_unlock(&(p->sleep));
}
