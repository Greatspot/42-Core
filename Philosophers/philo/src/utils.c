/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 19:41:30 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-05-17 19:33:42 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <sys/time.h>

long long	timestamp(void)
{
	struct timeval	time;
	unsigned long	l;
	unsigned long	s;
	unsigned long	u;

	gettimeofday(&time, NULL);
	s = (time.tv_sec * 1000);
	u = (time.tv_usec / 1000);
	l = s + u;
	return (l);
}

unsigned int	real_time(long long time)
{
	long long	now;

	now = timestamp();
	return ((unsigned int)(now - time));
}

static int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (write(2, str, len));
}

int	ft_error(int error)
{
	if (error == EINVAL)
		write_error("Invalid arguments\n");
	if (error == ENOMEM)
		write_error("Out of memory\n");
	return (error);
}
