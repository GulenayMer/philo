/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/05 18:47:31 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* initiliazing the arguments */
int	get_args(t_pro *process, int argc, char **argv)
{
	process->n_philos = ft_atoi(argv[1]);
	process->time_to_die = ft_atoi(argv[2]);
	process->time_to_eat = ft_atoi(argv[3]);
	process->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		process->n_meals = ft_atoi(argv[5]);
	else
		process->n_meals = -1;
	return (0);
}

void	init_args(t_pro *process)
{
	
		
}

/* pthread_create starts/initiliazes a new thread in the calling process */
long int	philosophers(t_pro *process, pthread_t *tid_philosophers)
{
	int			i;
	int			*philosophers;

	i = 0;
	while (i < process->n_philos)
	{
		philosophers[i] = i;
		if (pthread_create(&tid_philosophers[i], NULL, &routine, &philosophers[i]) != 0)
			return (3);
		i++;
	}
	i = 0;
	while (i < process->n_philos)
	{
		if (pthread_join(tid_philosophers[i], NULL) != 0)
			return (4);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_pro		process;
	pthread_t	*tid_philosophers;

	if (argc < 5)
		return (1);
	tid_philosophers = malloc(sizeof(t_pro) * process.n_philos);
	if (!tid_philosophers)
		return (2);
	get_args(&process, argc, argv);
	philosophers(&process, tid_philosophers);
	return (0);
}
