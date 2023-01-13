/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:35:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/06 18:25:08 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* check if number of arguments are valid & if arguments are numeric */
int	error_check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
		{
			printf("non-numeric arguments\n");
			return (1);
		}	
		i++;
	}
	return (0);
}

/* check if number of philos & mss are in the range */
int	arg_check(t_pro *process)
{
	if (process->n_philos < 1 || process->n_philos > 200)
	{
		printf("number of philosophers are invalid\n");
		return (1);
	}
	if (process->time_to_die < 60 || process->time_to_eat < 60 \
		|| process->time_to_sleep < 60)
	{
		printf("invalid ms\n");
		return (1);
	}
	return (0);
}
