/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 19:40:16 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-05-17 19:32:45 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADING_H
# define THREADING_H

# include "../inc/defines.h"

int		free_mutex(t_table *table);
int		threads_start(t_table *table);
int		threads_join(t_table *table);
void	*monitor(void *table_info);
void	*philo_thread(void *philosopher);
#endif
