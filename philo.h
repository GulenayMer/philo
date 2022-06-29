/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:05:07 by mgulenay          #+#    #+#             */
/*   Updated: 2022/06/29 21:29:16 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

typedef struct s_phil
{
	int			id;
	pthread_t	tid;
	int			left_fork;
	int			right_fork;
	long long	last_meal;
	int			meals_eaten;
	struct s_pro	*pro;
}	t_phil;

typedef struct s_pro
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	long long		start;
	int				end;
	int				is_dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	t_phil			*philos;
}		t_pro;

/* utils */
long		ft_atoi(char *nptr);
long long	get_time(void);
void		print_message(t_pro *process, t_phil *philos, char *message);

/* error check */
int			error_check(int argc, char **argv);
int			arg_check(t_pro *process);
int			ft_isnum(char *str);

/* inits */
int			get_args(t_pro *process, char **argv, int argc);
void		init_data(t_pro *process);
void		init_fork(t_pro *process);
void		create_tread(t_pro *process);

/* actions */
void		*routine(void *philosophers);
void		eat_sleep_think(t_pro *p, t_phil *ph);
void		eat_philo(t_pro *p, t_phil *ph);
int			dead_philo(t_pro *p, t_phil *ph);
void		sleep_philo(t_pro *p, t_phil *ph);
void		think_philo(t_pro *p, t_phil *ph);
void		dies_philo_sleep(t_pro *p, t_phil *ph);
#endif
