/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:05:07 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/05 18:22:41 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define MAX_PHILO 200;
# define FORK "has taken a fork";
# define EAT "is eating";
# define SLEEP "is sleeping";
# define THINK "is thinking";
# define DEAD "died";

typedef struct s_pro
{
	int	n_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_meals;
}		t_pro;

/* utils */
long	ft_atoi(char *nptr);

/* error check */

/* main */
int		get_args(t_philos *process, int argc, char **argv);
long	philosophers(t_philos *process, pthread_t *threads);

#endif
