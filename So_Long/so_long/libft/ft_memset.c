/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:47:59 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/23 17:48:01 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Fills the first 'n' bytes of the area pointed by 's'
 * with the given 'c' character.
 *
 * @param s Pointer to memory area
 * @param c Character to set
 * @param n Number of bytes to set
 * @return Returns the given Address
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}
