/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:48:28 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/23 17:48:29 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Combine deux chaînes en une nouvelle chaîne allouée dynamiquement.
 *
 * @param s1 Première chaîne.
 * @param s2 Deuxième chaîne.
 * @return Nouvelle chaîne résultant de la concaténation.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcat(join, s2, s1_len + s2_len + 1);
	return (join);
}
