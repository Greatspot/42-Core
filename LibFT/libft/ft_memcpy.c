/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:39:52 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:13:21 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copie n octets de mémoire dans un bloc de destination.
 *
 * @param dst Bloc mémoire de destination.
 * @param src Bloc mémoire source à copier.
 * @param n Nombre d'octets à copier.
 * @return Un pointeur vers le bloc de destination en cas de succès.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	const char		*source;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	source = (const char *)src;
	while (n--)
		*dst++ = *source++;
	return (dest);
}
