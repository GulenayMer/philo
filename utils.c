/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:47:32 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/06 18:17:02 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* for the 'think routine' */
void	think_philo(t_pro *p, t_phil *ph)
{
	print_message(p, ph, THINK);
}

/* lock the particular message and print it to know which action is taken */
void	print_message(t_pro *process, t_phil *philos, char *message)
{
	long long	current;

	current = get_time();
	pthread_mutex_lock(&(process->print_mutex));
	if (!process->end)
		printf("%05lld %d %s\n", current - process->time_start, \
			philos->id, message);
	pthread_mutex_unlock(&(process->print_mutex));
}

/* calculate the time in ms 
tv_sec, in seconds, 1 second = 1000 milliseconds
tv_usec, in microseconds, 1 microsecond = 0.001 milliseconds
*/
long long	get_time(void)
{
	struct timeval	time;
	long long		t_ms;

	gettimeofday(&time, NULL);
	t_ms = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (t_ms);
}

long	ft_atoi(char *nptr)
{
	long	result;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
