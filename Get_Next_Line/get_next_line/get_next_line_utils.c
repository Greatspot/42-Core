/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:36:35 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/09 18:45:42 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Recherche un caractère dans une chaîne.
 *
 * @param str Chaîne à analyser.
 * @param c Caractère à rechercher.
 * @return Pointeur vers la première occurrence ou NULL.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

/**
 * @brief Calcule la longueur d'une chaîne.
 *
 * @param s Chaîne d'entrée.
 * @return Longueur de la chaîne.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief Copie une zone mémoire.
 *
 * @param dest Destination.
 * @param src Source.
 * @param n Taille de la zone à copier.
 * @return Adresse de destination.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}

/**
 * @brief Alloue de la mémoire initialisée à zéro.
 *
 * @param nmemb Nombre d'éléments.
 * @param size Taille de chaque élément.
 * @return Pointeur vers la mémoire allouée ou NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	if (size && ((total_bytes / size) != nmemb))
		return (NULL);
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_bytes);
	return (ptr);
}

/**
 * @brief Concatène deux chaînes en une nouvelle.
 *
 * @param s1 Première chaîne.
 * @param s2 Deuxième chaîne.
 * @return Nouvelle chaîne concaténée.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}
