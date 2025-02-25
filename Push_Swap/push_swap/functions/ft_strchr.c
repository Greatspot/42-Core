/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 10:02:43 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 11:05:35 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Recherche un caractère spécifique dans une chaîne donnée 
 *        et retourne un pointeur vers sa première occurrence.
 * 
 * @param s La chaîne de caractères à analyser.
 * @param c Le caractère à rechercher.
 * @return Un pointeur vers la première occurrence du caractère dans la chaîne,
 *         ou NULL si le caractère n'est pas trouvé.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != (const char)c && *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
