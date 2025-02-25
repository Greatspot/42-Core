/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:38 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/10 19:10:42 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

// Libft Functions
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);

// Project-Specific Functions
void	convert_binary(int pid, char c);
void	send_msg(int pid, char *msg);

// Signal Handling Functions
void	handle_signal_client(int signum);
void	handle_signal_server(int signum, siginfo_t *info, void *context);

// Macros
# define WAIT_TIME 500

#endif