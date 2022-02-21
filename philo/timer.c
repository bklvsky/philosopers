/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:32:39 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/21 15:06:35 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	get_time_ms(void)
{
	struct timeval	time_now;	

	gettimeofday(&time_now, NULL);
	return (time_now.tv_sec * 1000 + time_now.tv_usec / 1000);
}

int	get_time_for_print(t_philo *philo)
{
	int		time_now;

	time_now = get_time_ms();
	return (time_now - philo->args.start_time);
}
