/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:56:03 by mgulenay          #+#    #+#             */
/*   Updated: 2022/07/06 18:25:15 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_pro		process;

	if (argc < 5 || argc > 6)
	{
		printf("number of arguments are invalid\n");
		return (1);
	}
	get_args(&process, argv, argc);
	if (arg_check(&process))
		return (1);
	if (error_check(argc, argv))
		return (1);
	init_data_for_philos(&process);
	ft_init_mutex(&process);
	ft_init_mutex2(&process);
	ft_create_tread(&process);
	ft_mutex_destroy(&process);
	ft_mutex_destroy2(&process);
	free_all(&process);
	return (0);
}
