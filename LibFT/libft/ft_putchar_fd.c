/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:43:45 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 19:02:00 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/**
 * Écrit un caractère dans le descripteur de fichier spécifié.
 *
 * @param c Caractère à écrire.
 * @param fd Descripteur de fichier où écrire.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
