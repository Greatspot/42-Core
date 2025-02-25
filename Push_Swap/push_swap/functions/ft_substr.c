/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 11:09:58 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 13:02:32 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 * 
 * @param str La chaîne de caractères dont la longueur doit être mesurée.
 * @return La longueur de la chaîne (nombre de caractères).
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

/**
 * @brief Crée une sous-chaîne à partir d'une chaîne donnée, 
 *        en commençant à un index spécifié et avec une longueur donnée.
 * 
 * @param s La chaîne source.
 * @param start L'index de départ de la sous-chaîne.
 * @param len La longueur maximale de la sous-chaîne.
 * @return Un pointeur vers la nouvelle sous-chaîne, ou NULL en cas d'échec.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	count = 0;
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	free (tab);
	return (tab);
}
