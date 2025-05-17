/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 19:40:59 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-05-17 19:33:22 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <limits.h>

static int	ft_atoi(const char *str, int *value)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	*value = res * neg;
	if ((res * neg) > INT_MAX || (res * neg) < INT_MIN)
		return (1);
	return (0);
}

int	parsing_args(int argv, char **argc, t_table *table)
{
	if (argv < 5)
		return (EINVAL);
	if (ft_atoi(argc[1], &table->num_philos) || \
		ft_atoi(argc[2], &table->data.time_to_die) || \
		ft_atoi(argc[3], &table->data.time_to_eat) || \
		ft_atoi(argc[4], &table->data.time_to_sleep))
		return (EINVAL);
	table->data.number_time_eats = -1;
	if (argv == 6)
	{
		if (ft_atoi(argc[5], &table->data.number_time_eats))
			return (EINVAL);
	}
	if (table->num_philos < 1)
		return (EINVAL);
	if (table->data.time_to_die < 0 || table->data.time_to_eat < 0 || \
		table->data.time_to_sleep < 0)
		return (EINVAL);
	return (0);
}
