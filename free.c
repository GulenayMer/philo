/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:06:55 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/06 15:13:33 by mgulenay         ###   ########.fr       */
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
	if (pthread_mutex_destroy(&p->print_mutex) != 0)
	{
		printf("Error in print mutex destroy\n");
		return (1);
	}
	if (pthread_mutex_destroy(&p->last_meal_mutex) != 0)
	{
		printf("Error in last meal mutex destroy\n");
		return (1);
	}
	return (0);
}

int	ft_mutex_destroy2(t_pro *p)
{
	if (pthread_mutex_destroy(&p->dead_mutex) != 0)
	{
		printf("Error in last meal mutex destroy\n");
		return (1);
	}
	if (pthread_mutex_destroy(&p->count_meals_mutex) != 0)
	{
		printf("Error in last meal mutex destroy\n");
		return (1);
	}
	if (pthread_mutex_destroy(&p->end_mutex) != 0)
	{
		printf("Error in end mutex destroy\n");
		return (1);
	}
	return (0);
}

void	free_all(t_pro *p)
{
	free(p->philos);
	free(p->fork_mutex);
}
