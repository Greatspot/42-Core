/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:47:44 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/23 17:47:47 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Alloue de la mémoire pour un tableau de pointeurs.
 *
 * @param nmemb Nombre d'éléments.
 * @param size Taille de chaque élément.
 * @return Renvoie un pointeur vers la mémoire allouée,
 * ou NULL en cas de dépassement de capacité ou d'échec d'allocation.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*s;
	size_t			n;

	n = nmemb * size;
	s = malloc(n);
	if (s == 0)
		return (0);
	return (ft_memset(s, 0, n));
}
