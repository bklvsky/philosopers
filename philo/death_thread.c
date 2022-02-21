/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:51:01 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/21 18:29:14 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	is_time_to_stop(t_philo *philo)
{
	int		ret;

	pthread_mutex_lock(philo->check_mutex);
	ret = *(philo->stop_flag);
	pthread_mutex_unlock(philo->check_mutex);
	return (ret);
}

int	philo_is_dead(t_philo *philo)
{
	long int	time_now;

	time_now = get_time_ms();
	if (time_now - philo->last_meal_time >= (long int)philo->args.time_to_die \
													&& !*(philo->stop_flag))
	{
		*(philo->stop_flag) = 1;
		printf("%d %d %s\n", get_time_for_print(philo), philo->num, "died");
		return (1);
	}
	return (0);
}

int	check_if_philos_have_eaten(t_philo *philo)
{
	int		i;

	i = -1;
	philo->left_to_eat -= 1;
	if (philo->left_to_eat == 0)
	{
		*(philo->ate_everything) = 1;
		while (++i < philo->args.num_of_philos)
		{
			if (!philo->eat_count[i])
				return (0);
		}
		*(philo->stop_flag) = 1;
	}
	else
		return (0);
	return (1);
}

void	*death_check_thread(void *structure)
{
	t_philo	*philo;

	philo = (t_philo *)structure;
	while (1)
	{
		pthread_mutex_lock(philo->print_mutex);
		pthread_mutex_lock(philo->check_mutex);
		if (philo_is_dead(philo) || *(philo->stop_flag))
			break ;
		pthread_mutex_unlock(philo->check_mutex);
		pthread_mutex_unlock(philo->print_mutex);
		usleep(100);
	}
	pthread_mutex_unlock(philo->check_mutex);
	pthread_mutex_unlock(philo->print_mutex);
	if (philo->args.num_of_philos == 1)
		pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}
