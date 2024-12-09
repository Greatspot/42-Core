/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:43:21 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:21:27 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Transfère n octets de la zone mémoire src vers la zone mémoire dest.
 * En cas de chevauchement, copie uniquement les zones non superposées.
 *
 * @param dest Pointeur vers la zone de destination.
 * @param src Pointeur vers les données à copier.
 * @param n Nombre d'octets à transférer.
 * @return Pointeur vers dest.
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src_ptr;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (src_ptr < dst && (src_ptr + n) > dst)
	{
		while (n--)
			*(dst + n) = *(src_ptr + n);
	}
	else
	{
		while (n--)
			*dst++ = *src_ptr++;
	}
	return (dest);
}
