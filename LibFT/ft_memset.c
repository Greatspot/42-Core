/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:43:37 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:21:50 by rcunha-l         ###   ########.fr       */
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
