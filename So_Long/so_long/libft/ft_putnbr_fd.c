/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:48:16 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/23 17:48:17 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Écrit un nombre spécifié dans le descripteur de fichier donné.
 *
 * @param n Nombre à écrire.
 * @param fd Descripteur de fichier de destination.
 */
void	ft_putnbr_fd(int n, int fd)
{
	long	num_long;

	num_long = n;
	if (num_long < 0)
	{
		ft_putchar_fd('-', fd);
		num_long = -num_long;
	}
	if (num_long >= 10)
	{
		ft_putnbr_fd(num_long / 10, fd);
	}
	ft_putchar_fd('0' + (num_long % 10), fd);
}
