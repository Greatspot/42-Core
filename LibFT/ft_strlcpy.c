/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:47:53 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:28:40 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copie jusqu'à size - 1 octets de src vers dest,
 * en s'assurant que dest soit terminé par un caractère null.
 *
 * @param dest Chaîne de destination.
 * @param src Chaîne source à copier.
 * @param size Nombre d'octets maximum à copier.
 * @return Renvoie la longueur de src (strlen(src)).
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (src[count])
		count++;
	if (size)
	{
		while (--size && *src)
			*dest++ = *src++;
		*dest = 0;
	}
	return (count);
}
