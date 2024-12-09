/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:43 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:32:23 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Extrait une sous-chaîne à partir d'une chaîne principale.
 *
 * @param s Chaîne principale.
 * @param start Position de début de la sous-chaîne.
 * @param len Longueur maximale de la sous-chaîne.
 * @return Renvoie la sous-chaîne extraite ou NULL en cas d'échec.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	size_t			str_len;
	unsigned int	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len <= start)
		len = 0;
	else if (len > str_len - start)
		len = str_len - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < (unsigned int)len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
/*
int	main(void)
{
	printf("%s", ft_substr("Hello World!", 6, 6));
	return (0);
}
*/