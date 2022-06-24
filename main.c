/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/24 23:54:49 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eating(void *philosophers)
{
	//int		i;
	t_pro	*p;
	t_phil	*ph;

	ph = (t_phil *)philosophers;
	p = ph->pro;

	printf("philo id = %d\n",ph->id);
/* 	i = 0;
	while (i < p->n_philos)
	{ */
		//pro->philos[i].last_meal = get_time();
		if ((ph->id) % 2 == 0)
		{
			pthread_mutex_lock(&(p->fork[0]));
			// pthread_mutex_lock(&(p->fork[ph->left_fork]));
			puts("hi");
			pthread_mutex_lock(&p->fork[1]);
			// pthread_mutex_lock(&p->fork[ph->right_fork]);
			printf("fork worked");
			pthread_mutex_unlock(&p->fork[0]);
			pthread_mutex_unlock(&p->fork[1]);
			// pthread_mutex_unlock(&p->fork[ph->left_fork]);
			// pthread_mutex_unlock(&p->fork[ph->right_fork]);
		}
/* 		i++;
	} */
	printf("eating\n");
	return (0);
}

/* void	*routine(void *philosophers)
{
	t_pro	*process;
	t_phil	*ph;

	ph = (t_phil *)philosophers;
	fork_init(process);
	eating(process);
	printf("eating\n");
	return (0);
} */

/* pthread_create starts/initiliazes a new thread in the calling process*/
long int	philosophers(t_pro *process)
{
	int			i;

	i = 0;
	// printf("hi%p\n",&process->fork[0]);

	while (i < process->n_philos)
	{
		if ((pthread_create(&(process->philos[i].tid), NULL, &eating,
				&(process->philos[i]))) != 0)
			printf("Error with creating thread\n");
		i++;
	}
	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_join(process->philos[i].tid, NULL) != 0)
			printf("Error with joining thread\n");
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
	init_all(&process);
	// printf("%p\n",&process.fork[0]);
	printf("%d\n", process.philos[3].left_fork);
	printf("%d\n", process.philos[3].right_fork);
	// fork_init(&process);
	philosophers(&process);
	return (0);
}
