/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 11:02:48 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 12:05:18 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Crée une nouvelle chaîne de caractères qui est une duplication
 *        de la chaîne d'entrée. Alloue dynamiquement de la mémoire et 
 *        copie le contenu de la chaîne source.
 * 
 * @param s La chaîne de caractères à dupliquer.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL en cas d'échec.
 */
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_alloc;

	len = ft_strlen(s) + 1;
	s_alloc = (char *)malloc(len * sizeof(char));
	if (s_alloc == NULL)
		return (NULL);
	ft_memcpy(s_alloc, s, len);
	free (s_alloc);
	return (s_alloc);
}
