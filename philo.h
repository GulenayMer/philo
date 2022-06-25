/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:05:07 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/25 17:52:24 by mgulenay         ###   ########.fr       */
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

typedef struct s_phil
{
	int			id;
	pthread_t	tid;
	int			left_fork;
	int			right_fork;
	long long	last_meal;
	int 		is_dead;
	struct s_pro *pro;
}	t_phil;

typedef struct s_pro
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_phil			*philos;
}		t_pro;

/* utils */
long		ft_atoi(char *nptr);
long long	get_time(void);

/* error check */
int			error_check(int argc, char **argv);
int			ft_isnum(char *str);

/* inits */
int			get_args(t_pro *process, char **argv, int argc);
void		init_data(t_pro *process);
void		init_fork(t_pro *process);
void		create_tread(t_pro *process);

/* actions */
void		eat_philo(t_pro *process);
void		*routine(void *philosophers);

#endif
