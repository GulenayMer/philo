/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:05:07 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/01 14:07:55 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

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
	long long	time_last_meal;
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
	long long		time_start;
	int				end;
	int				flag_dead;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	last_meal_mutex;
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
int			init_data_for_philos(t_pro *process);
int			ft_init_fork(t_pro *process);
int			ft_create_tread(t_pro *process);
int			ft_join_tread(t_pro *process);
int			ft_init_mutex(t_pro *process);

/* actions */
void		*routine(void *philosophers);
void	lock_all(t_pro *p);
int			eat_sleep_think(t_pro *p, t_phil *ph);
int			eat_philo(t_pro *p, t_phil *ph);
int			dead_philo(t_pro *p);
int			sleep_philo(t_pro *p, t_phil *ph);
int			think_philo(t_pro *p, t_phil *ph);
void		eat_util(t_pro *p, t_phil *ph);

/* */
int			ft_mutex_destroy(t_pro *p);
void		free_all(t_pro *p);

#endif
