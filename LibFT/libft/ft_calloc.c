/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:52:18 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:46:47 by rcunha-l         ###   ########.fr       */
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
	void	*memory;
	size_t	bytes_needed;

	bytes_needed = nmemb * size;
	if (size && ((bytes_needed / size) != nmemb))
		return (NULL);
	memory = malloc(bytes_needed);
	if (!memory)
		return (NULL);
	ft_bzero(memory, bytes_needed);
	return (memory);
}
