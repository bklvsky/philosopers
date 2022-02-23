/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:09:48 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/23 20:57:12 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_to_eat;
	int			start_time;
}				t_args;

typedef struct s_philo
{
	int				num;
	int				last_meal_time;
	t_args			args;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*waiter;
	pthread_mutex_t	*print_mutex;
	int				left_to_eat;
	int				*eat_count;
	int				*ate_everything;
	int				*stop_flag;
}					t_philo;

typedef struct s_data
{
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	waiter;
	pthread_mutex_t	print_mutex;
	int				*eat_count;
	int				stop_flag;
	t_args			args;
}					t_data;

# define ERR_ARG -2

int		parse_arguments(int argc, char **argv, t_args *data);

int		init_data(t_data *data);

int		ft_atoi(const char *ptr);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memset(void *dest, int c, size_t n);

void	*philo_life(void *structure);
void	eat(t_philo *philo);
void	philo_wait(long int time_to_wait, t_philo *philo);
void	take_forks(t_philo *philo);
int		check_if_philos_have_eaten(t_philo *philo);

void	put_message(t_philo *philo, char *str);

void	*death_check_thread(void *structure);
int		philo_is_dead(t_philo *philo);

int		get_time_ms(void);
int		get_time_for_print(t_philo *philo);

void	free_all(t_data data);
void	free_forks(pthread_mutex_t **forks, int num_of_forks);

#endif
