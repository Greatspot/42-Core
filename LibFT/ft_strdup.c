/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:47:03 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:26:02 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates space for a new string and copies the values from the given one.
 *
 * @param s String to duplicate.
 * @return Returns a pointer to the newly duplicated string,
 * or NULL if memory allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	s_length;

	s_length = ft_strlen(s);
	dst = ft_calloc(s_length + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, s_length + 1);
	return (dst);
}
