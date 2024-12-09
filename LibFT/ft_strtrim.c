/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:36 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:31:42 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Supprime les caractères spécifiés du début et de la fin d'une chaîne.
 *
 * @param s1 Chaîne à élaguer.
 * @param set Ensemble de caractères à retirer.
 * @return Renvoie une nouvelle chaîne allouée avec les caractères retirés,
 * ou NULL en cas d'échec.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	new_len;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	new_len = ft_strlen(s1);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
		new_len--;
	}
	while (new_len && ft_strchr(set, s1[new_len - 1]))
		new_len--;
	trimmed_str = (char *)malloc(new_len + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1, new_len + 1);
	return (trimmed_str);
}
