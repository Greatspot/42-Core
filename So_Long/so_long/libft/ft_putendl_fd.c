/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:48:08 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/23 17:48:09 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Écrit une chaîne de caractères suivie d'un saut de ligne
 * dans le descripteur de fichier spécifié.
 *
 * @param s Chaîne à écrire.
 * @param fd Descripteur de fichier de destination.
 */
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
