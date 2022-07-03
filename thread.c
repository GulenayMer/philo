/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:39 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/01 14:07:36 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* pthread_create starts a new thread in the calling process and makes it executable */
int	ft_create_tread(t_pro *process)
{
	int	i;

	i = 0;
	process->time_start = get_time();
	process->end = 0;
	while (i < process->n_philos)
	{
		process->philos[i].time_last_meal = get_time();
		if ((pthread_create(&(process->philos[i].tid), NULL, &routine, \
			&(process->philos[i]))) != 0)
		{
			printf("Error with creating thread\n");
			return (1);
		}
		i++;
	}
	//dead_philo(process);
	ft_join_tread(process);
	return (0);
}

int	ft_join_tread(t_pro *process)
{
	int	i;

	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_join(process->philos[i].tid, NULL) != 0)
		{
			printf("Error with joining thread\n");
			return (1);
		}
		i++;
	}
	return (0);
}
