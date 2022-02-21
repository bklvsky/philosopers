/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:49:09 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/21 18:40:57 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_wait(long int time_to_wait, t_philo *philo)
{
	long int	time_start;
	long int	time_now;

	time_start = get_time_ms();
	time_now = get_time_ms();
	while (time_now - time_start < time_to_wait && !is_time_to_stop(philo))
	{
		usleep(10);
		time_now = get_time_ms();
	}
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->waiter);
	if (!is_time_to_stop(philo))
		pthread_mutex_lock(philo->left_fork);
	put_message(philo, "has taken a fork");
	if (!is_time_to_stop(philo))
		pthread_mutex_lock(philo->right_fork);
	put_message(philo, "has taken a fork");
	pthread_mutex_unlock(philo->waiter);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	pthread_mutex_lock(philo->check_mutex);
	if (!philo_is_dead(philo) && !*(philo->stop_flag))
	{
		printf("%d %d %s\n", get_time_for_print(philo), philo->num, "is eating");
		philo->last_meal_time = get_time_ms();
		pthread_mutex_unlock(philo->print_mutex);
		if (philo->left_to_eat > 0)
			check_if_philos_have_eaten(philo);
		pthread_mutex_unlock(philo->check_mutex);
		philo_wait(philo->args.time_to_eat, philo);
	}
	else
	{
		pthread_mutex_unlock(philo->check_mutex);
		pthread_mutex_unlock(philo->print_mutex);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philo_life(void *structure)
{
	t_philo		*philo;
	pthread_t	death_thread;

	philo = (t_philo *)structure;
	pthread_create(&death_thread, NULL, &death_check_thread, philo);
	pthread_detach(death_thread);
	while (!*(philo->stop_flag))
	{
		take_forks(philo);
		eat(philo);
		put_message(philo, "is sleeping");
		philo_wait(philo->args.time_to_sleep, philo);
		put_message(philo, "is thinking");
	}
	return (NULL);
}
