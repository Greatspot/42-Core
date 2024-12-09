/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:39:29 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:12:08 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Parcourt les n premiers octets d'une zone mémoire pour trouver 
 * la première occurrence de c.
 *
 * @param s Pointeur vers la zone mémoire à examiner.
 * @param c Caractère à localiser.
 * @param n Nombre d'octets à parcourir.
 * @return Renvoie un pointeur vers la première occurrence de c,
 * ou NULL si c n'est pas trouvé.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
