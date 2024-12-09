/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:04 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:30:23 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compare les n premiers octets des chaînes s1 et s2.
 *
 * @param s1 Première chaîne.
 * @param s2 Deuxième chaîne.
 * @param n Nombre d'octets à comparer.
 * @return Renvoie 0 si s1 et s2 sont égales.
 * Renvoie une valeur négative (différence des valeurs ASCII)
 * si s1 est inférieure à s2.
 * Renvoie une valeur positive (différence des valeurs ASCII)
 * si s1 est supérieure à s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
