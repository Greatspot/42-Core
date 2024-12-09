/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:39:40 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:12:50 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compare les n premiers octets de la zone mémoire pointée par s1
 * avec ceux de la zone pointée par s2.
 *
 * @param s1 Pointeur vers la première zone mémoire à comparer avec s2.
 * @param s2 Pointeur vers la seconde zone mémoire à comparer avec s1.
 * @param n Nombre d'octets à comparer.
 * @return Renvoie 0 si s1 et s2 sont identiques.
 * Renvoie une valeur négative (différence des valeurs ASCII) 
 * si s1 est inférieur à s2.
 * Renvoie une valeur positive (différence des valeurs ASCII) 
 * si s1 est supérieur à s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_char1;
	unsigned char	*s_char2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	s_char1 = (unsigned char *)s1;
	s_char2 = (unsigned char *)s2;
	while (i < n - 1 && s_char1[i] == s_char2[i])
	{
		i++;
	}
	return (s_char1[i] - s_char2[i]);
}
