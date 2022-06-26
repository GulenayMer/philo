/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/26 19:51:45 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_pro *p, t_phil *ph)
{
	pthread_mutex_lock(&(p->fork[ph->left_fork]));
	pthread_mutex_lock(&(p->fork[ph->right_fork]));
	print_message(p, ph, FORK);
	print_message(p, ph, FORK);
	pthread_mutex_unlock(&(p->fork[ph->left_fork]));
	pthread_mutex_unlock(&(p->fork[ph->right_fork]));
}

void	eat_philo(t_pro *p, t_phil *ph)
{
	int	i;

	i = 0;
	while (i < p->n_philos)
	{
		if (ph[i].id % 2 != 0)
		{
			get_fork(p, ph);
		}
		i++;
	}
}

/* simulation for each philosopher */
void	*routine(void *philosophers)
{
	t_pro	*p;
	t_phil	*ph;

	ph = (t_phil *)philosophers;
	p = ph->pro;
	while (!p->end)
	{
		eat_philo(p, ph);
		dead_philo(p, ph);
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
