/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:21:39 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/23 17:59:00 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_forks(pthread_mutex_t **forks, int num_of_forks)
{
	if (*forks)
	{
		while (--num_of_forks >= 0)
		{
			if (*forks + num_of_forks)
				pthread_mutex_destroy(*forks + num_of_forks);
		}
		free(*forks);
	}
	*forks = NULL;
}

void	free_all(t_data data)
{
	free_forks(&data.forks, data.args.num_of_philos);
	free(data.eat_count);
	free(data.philosophers);
	pthread_mutex_destroy(&data.waiter);
	pthread_mutex_destroy(&data.print_mutex);
}
