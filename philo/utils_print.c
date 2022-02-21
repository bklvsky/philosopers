/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:58:08 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/21 18:13:37 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	put_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print_mutex);
	if (!is_time_to_stop(philo))
		printf("%d %d %s\n", get_time_for_print(philo), philo->num, str);
	pthread_mutex_unlock(philo->print_mutex);
}

void	put_death_message(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("%d %d %s\n", get_time_for_print(philo), philo->num, "died");
	pthread_mutex_unlock(philo->print_mutex);
}
