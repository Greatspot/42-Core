/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:47:43 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:28:12 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ajoute src à la fin de dest en s'assurant que dest ne dépasse pas
 * la capacité et reste terminé par un caractère null.
 *
 * @param dest Chaîne de destination à laquelle src sera ajoutée.
 * @param src Chaîne à concaténer à la fin de dest.
 * @param size Nombre de bytes maximum pour la concaténation.
 * @return Si size est inférieur à strlen(dest), retourne strlen(src) + size.
 * Sinon, retourne strlen(dest) + strlen(src).
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	space_left;

	src_len = ft_strlen(src);
	if (!dest && !size)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (src_len + size);
	space_left = size - dest_len - 1;
	dest += dest_len;
	while (space_left-- > 0 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_len + src_len);
}
