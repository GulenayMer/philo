/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:05:07 by mgulenay          #+#    #+#             */
/*   Updated: 2022/05/27 17:59:30 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philos
{
	int	time_to_eat;
	int time_to_sleep;
	int time_to_think;
	int time_to_die;
	int n_philos;
	int n_meals;
	
}		t_philos;

/* utils */
long		ft_atoi(char *nptr);
int	init_args(t_philos *process, int argc, char **argv);
long		philosophers(t_philos *process, pthread_t *threads);


/* error check */

/* routines */
void *routine();


#endif
