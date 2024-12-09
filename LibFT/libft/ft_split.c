/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:46:14 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:25:19 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calcule le nombre de « words » présents dans la chaîne de caractères donnée.
 *
 * @param s Chaîne dans laquelle compter les mots.
 * @param c Caractère utilisé comme séparateur.
 * @return Renvoie le nombre de « words » contenus dans la chaîne spécifiée.
 */
static unsigned int	ft_count_words(const char *s, char c)
{
	unsigned int	word_count;
	int				in_word;

	word_count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			word_count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (word_count);
}

/**
 * Alloue et copie un nombre spécifié de caractères depuis la chaîne donnée
 * vers un nouveau « words ».
 *
 * @param start Chaîne source pour commencer la copie.
 * @param len Nombre de caractères à copier.
 * @return Renvoie un « words » terminé par un caractère null.
 */
static char	*ft_alloc_word(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/**
 * Libère toutes les fonctions précédemment allouées dans un tableau,
 * ainsi que le tableau lui-même.
 *
 * @param split Tableau de chaînes à libérer.
 * @param i Index actuel dans le tableau.
 */
static void	ft_free_split(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

/**
 * Remplit le tableau de chaînes donné avec les « words »
 * (délimités par le séparateur ou par le début/fin de la chaîne).
 *
 * @param split Tableau de chaînes à compléter.
 * @param s Chaîne à découper en mots.
 * @param c Caractère séparateur.
 * @return Renvoie un tableau de chaînes terminé par un null, 
 * contenant les « words ».
 */
static char	**ft_fill_split(char **split, const char *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			split[i++] = ft_alloc_word(s - len, len);
			if (!split[i - 1])
				return (ft_free_split(split, i - 1), NULL);
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

/**
 * Divise une chaîne en « words ».
 *
 * @param s Chaîne à diviser.
 * @param c Caractère séparateur.
 * @return Renvoie un tableau de chaînes, terminé par un null,
 * contenant les « words » délimités par le séparateur ou par le début/fin.
 */
char	**ft_split(const char *s, char c)
{
	unsigned int	n_words;
	char			**split;

	if (!s)
		return (NULL);
	n_words = ft_count_words(s, c);
	split = (char **)malloc((n_words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_fill_split(split, s, c));
}
/*
#include <stdio.h>

int	main(void)
{
	char	**split;
	int	n_strings;

	n_strings = 2;
	split = ft_split(" hello world ", ' ');
	for (int i = 0; i < n_strings; i++)
		printf("%s\n", split[i]);
	ft_free_split(split, 2);
	return (0);
}
*/