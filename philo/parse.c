/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:01:24 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/21 15:58:53 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_arguments(int argc, char **argv, t_args *data)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_to_eat = ft_atoi(argv[5]);
	else
		data->num_to_eat = -1;
	if (data->num_of_philos <= 0 || data->time_to_die < 0 || data->time_to_eat \
	< 0 || data->time_to_sleep < 0 || data->num_to_eat == ERR_ARG || \
														data->num_to_eat == 0)
	{
		write(2, "Error in arguments\n", 19);
		exit(1);
	}
}
