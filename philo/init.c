/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:46:20 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/21 15:12:01 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static pthread_mutex_t	*init_forks(int num_of_philos)
{
	pthread_mutex_t	*forks;
	int				i;

	i = -1;
	forks = (pthread_mutex_t *)ft_calloc(num_of_philos, \
													sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	while (++i < num_of_philos)
	{
		if (pthread_mutex_init(forks + i, NULL) != 0)
		{
			free_forks(&forks, i);
			return (NULL);
		}
	}
	return (forks);
}

static t_philo	*init_philos(int num_of_philos, t_data *data)
{
	int			i;
	t_philo		*philos;

	i = -1;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->args.num_of_philos);
	if (!philos)
		return (NULL);
	data->args.start_time = get_time_ms();
	while (++i < num_of_philos)
	{
		philos[i].num = i + 1;
		philos[i].args = data->args;
		philos[i].last_meal_time = data->args.start_time;
		philos[i].left_fork = data->forks + i;
		philos[i].right_fork = data->forks + ((i + 1) % num_of_philos);
		philos[i].waiter = &data->waiter;
		philos[i].print_mutex = &data->print_mutex;
		philos[i].left_to_eat = data->args.num_to_eat;
		philos[i].eat_count = data->eat_count;
		philos[i].ate_everything = data->eat_count + i;
		philos[i].stop_flag = &data->stop_flag;
		philos[i].check_mutex = &data->check_mutex;
	}
	return (philos);
}

int	init_data(t_data *data)
{
	data->stop_flag = 0;
	data->eat_count = (int *)ft_calloc(sizeof(int), data->args.num_of_philos);
	data->forks = init_forks(data->args.num_of_philos);
	if (!data->forks || !data->eat_count)
		return (-1);
	data->philosophers = init_philos(data->args.num_of_philos, data);
	if (!data->philosophers)
		return (-1);
	if (pthread_mutex_init(&data->waiter, NULL) != 0 || \
	pthread_mutex_init(&data->print_mutex, NULL) != 0 || \
	pthread_mutex_init(&data->check_mutex, NULL) != 0)
		return (-1);
	return (0);
}
