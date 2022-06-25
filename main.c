/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/25 19:27:16 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_philo(t_pro *process)
{
	int	i;

	i = 0;
	while (i < process->n_philos)
	{
		if (process->philos[i].id % 2 != 0)
		{
			pthread_mutex_lock(&(process->fork[process->philos[i].left_fork]));
			printf("index: %d %s the first fork\n ", process->philos[i].id, FORK);
			pthread_mutex_lock(&process->fork[process->philos[i].right_fork]);
			printf("index: %d %s the second fork\n ",  process->philos[i].id, FORK);
			pthread_mutex_unlock(&(process->fork[process->philos[i].left_fork]));
			pthread_mutex_unlock(&(process->fork[process->philos[i].right_fork]));
		}
		i++;
	}
}

void	*routine(void *philosophers)
{
	t_pro	*p;
	t_phil	*ph;

	ph = (t_phil *)philosophers;
	p = ph->pro;
	//printf("eating, %d\n", ph->id);
	eat_philo(p);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pro		process;

	if (argc < 2)
		return (1);
	get_args(&process, argv, argc);
	init_data(&process);
/* 	//printf("%p\n",&process.fork[0]);
	printf("%d\n", process.philos[2].left_fork);
	printf("%d\n", process.philos[2].right_fork); */
	create_tread(&process);
	return (0);
}
