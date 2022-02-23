/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:15:30 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/23 20:52:50 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	launch_philo(t_data *data)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	threads = (pthread_t *)malloc(sizeof(pthread_t) * data->args.num_of_philos);
	if (!threads)
		return ;
	while (i < data->args.num_of_philos)
	{
		pthread_create(threads + i, NULL, &philo_life, data->philosophers + i);
		i += 2;
		usleep(10);
		if (i % 2 == 0)
		{
			if (i >= data->args.num_of_philos)
				i = 1;
		}
	}
	i = -1;
	while (++i < data->args.num_of_philos)
		pthread_join(threads[i], NULL);
	free(threads);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 5 && argc != 6)
	{
		write(2, "Usage: number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 112);
		return (1);
	}
	if (parse_arguments(argc, argv, &(data.args)) < 0)
		return (1);
	if (init_data(&data) != -1)
		launch_philo(&data);
	else
		write(2, "Memory error\n", 13);
	usleep(100);
	free_all(data);
	return (0);
}
