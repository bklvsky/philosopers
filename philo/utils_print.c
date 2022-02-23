/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:58:08 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/23 21:18:13 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	put_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print_mutex);
	if (!philo_is_dead(philo) && !*(philo->stop_flag))
		printf("%d %d %s\n", get_time_for_print(philo), philo->num, str);
	pthread_mutex_unlock(philo->print_mutex);
}
