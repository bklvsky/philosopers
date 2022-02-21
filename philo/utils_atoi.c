/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:06:35 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/17 22:28:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i] || ptr1[i] == '\0')
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

static int	check_int_overflow(const char *ptr)
{
	if (ft_strlen(ptr) >= 10 && ft_strncmp(ptr, "2147483648", 11) > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *ptr)
{
	unsigned long		value;

	value = 0;
	if (check_int_overflow(ptr) < 0)
		return (ERR_ARG);
	while (*ptr == ' ' || (*ptr >= '\t' && *ptr <= '\r'))
		ptr += 1;
	if (*ptr == '+')
		ptr += 1;
	if (*ptr == '-')
		return (ERR_ARG);
	while (ft_isdigit(*ptr))
	{
		value = 10 * value + (*ptr - '0');
		ptr += 1;
	}
	if (*ptr)
		return (ERR_ARG);
	return ((int)value);
}
