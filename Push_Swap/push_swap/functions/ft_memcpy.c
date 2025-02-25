/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 10:09:36 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 11:02:34 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Copie n octets de la zone mémoire source (src) vers la zone 
 * mémoire destination (dest). Fonctionne même si les zones se chevauchent.
 * 
 * @param dest Pointeur vers la zone mémoire de destination.
 * @param src Pointeur vers la zone mémoire source.
 * @param n Nombre d'octets à copier.
 * @return Pointeur vers la zone mémoire de destination.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*pt_src;
	unsigned char		*pt_dest;
	size_t				i;

	pt_dest = (unsigned char *)dest;
	pt_src = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*((char *)dest + i) = *((char *)pt_src + i);
		i++;
	}
	return (pt_dest);
}
