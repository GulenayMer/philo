
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:47:32 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/30 22:05:20 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_destroy(t_pro *p)
{
 	int	i;

	i = 0;
	while (i < p->n_philos)
	{
		if (pthread_mutex_destroy(&p->fork_mutex[i]) != 0)
		{
			printf("Error in fork_mutex destroy\n");
			return (1);
		}
		i++;
	}
	if (pthread_mutex_destroy(&p->print_mutex) != 0 )
	{
		printf("Error in print mutex destroy\n");
		return (1);	
	}
	if (pthread_mutex_destroy(&p->last_meal_mutex) != 0 )
	{
		printf("Error in last meal mutex destroy\n");
		return (1);	
	}
	if (pthread_mutex_destroy(&p->dead_mutex) != 0 )
	{
		printf("Error in last meal mutex destroy\n");
		return (1);	
	}
	return (0);
}

void	free_all(t_pro *p)
{
	free(p->philos);
	free(p->fork_mutex);
}
