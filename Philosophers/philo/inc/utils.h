/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 19:40:39 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-05-17 19:32:55 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../inc/defines.h"

unsigned int	real_time(long long time);
void			philo_sleep(long long time, char *dead);
long long		timestamp(void);
int				ft_error(int error);
int				status_print(t_philo *philo, char *str, char *color, \
				int print_death);
int				ft_atoi(const char *str);
int				parsing_args(int argv, char **argc, t_table *table);
#endif
