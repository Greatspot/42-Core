/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:40:56 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/09 19:48:45 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Localise un caractère dans une chaîne.
 *
 * @param str Chaîne où chercher.
 * @param c Caractère à localiser.
 * @return Pointeur vers la première occurrence de c ou NULL.
 */
char	*ft_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

/**
 * @brief Calcule la longueur d'une chaîne.
 *
 * @param str Chaîne à mesurer.
 * @return Longueur de la chaîne.
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/**
 * @brief Copie une zone mémoire.
 *
 * @param dest Destination.
 * @param src Source.
 * @param n Nombre d'octets à copier.
 * @return Adresse de la destination.
 */
void	*ft_memset(void *ptr, int c, size_t n)
{
	while (n--)
		*((unsigned char *)(ptr + n)) = c;
	return (ptr);
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
	if (size && (total_bytes / size) != nmemb)
		return (NULL);
	ptr = (void *)malloc(total_bytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_bytes);
	return (ptr);
}

/**
 * @brief Concatène deux chaînes.
 *
 * @param s1 Première chaîne.
 * @param s2 Deuxième chaîne.
 * @return Nouvelle chaîne concaténée.
 */
char	*ft_strjoin(char *s1, char *s2)
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
