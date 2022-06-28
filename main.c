/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/29 00:11:48 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_pro *p, t_phil *ph)
{
	pthread_mutex_lock(&(p->fork[ph->left_fork]));
	pthread_mutex_lock(&(p->fork[ph->right_fork]));
	print_message(p, ph, FORK);
	print_message(p, ph, FORK);
	print_message(p, ph, EAT);
	usleep(p->time_to_eat * 1000);
	pthread_mutex_unlock(&(p->fork[ph->left_fork]));
	pthread_mutex_unlock(&(p->fork[ph->right_fork]));
	sleep_philo(p, ph);
	think_philo(p, ph);
}

/* simulation for each philosopher */
void	*routine(void *philosophers)
{
	t_pro	*p;
	t_phil	*ph;
	int i=0;

	ph = (t_phil *)philosophers;
	p = ph->pro;
 	while (i < 1000)
	{ 
		if (ph->id % 2 != 0)
		{
			usleep(p->time_to_eat * 1000);
		
		}
		get_fork(p, ph);
		i++;
	}
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
