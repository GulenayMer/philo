/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/25 17:47:15 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	void	eat_philo(t_pro *process)
	{
		printf("index: %d\n", process->philos[0].id);
		pthread_mutex_lock(&(process->fork[process->philos[0].left_fork]));
		printf("FORK");
		//pthread_mutex_lock(&process->fork[process->philos->right_fork]);
	pthread_mutex_unlock(&(process->fork[process->philos[0].left_fork]));
	//	pthread_mutex_unlock(&p->fork[ph->right_fork]);
	}

void	*routine(void *philosophers)
{
	t_pro	*p;
	t_phil	*ph;

	ph = (t_phil *)philosophers;
	p = ph->pro;
	printf("eating, %d\n", ph->id);
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
	pthread_mutex_init(&process.print, NULL);
	//printf("%p\n",&process.fork[0]);
	printf("%d\n", process.philos[2].left_fork);
	printf("%d\n", process.philos[2].right_fork);
	create_tread(&process);
	return (0);
}
