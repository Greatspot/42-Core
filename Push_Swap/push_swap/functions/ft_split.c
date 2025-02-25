/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 10:02:38 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 11:10:24 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Compte le nombre de mots dans une chaîne de caractères en fonction
 *        d'un séparateur donné.
 * 
 * @param str La chaîne de caractères à analyser.
 * @param c Le caractère séparateur des mots.
 * @return Le nombre total de mots trouvés dans la chaîne.
 */
static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

/**
 * @brief Copie un mot extrait d'une chaîne dans une nouvelle chaîne.
 * 
 * @param word Pointeur vers la mémoire où stocker le mot.
 * @param s La chaîne d'origine.
 * @param i Index de fin du mot dans la chaîne source.
 * @param word_len Longueur du mot à copier.
 * @return Pointeur vers la chaîne contenant le mot copié.
 */
static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

/**
 * @brief Découpe une chaîne de caractères en un tableau de sous-chaînes
 *        en fonction d'un délimiteur donné.
 * 
 * @param s La chaîne de caractères à découper.
 * @param c Le caractère utilisé comme séparateur.
 * @param s2 Pointeur vers le tableau où stocker les sous-chaînes.
 * @param num_words Nombre total de mots à extraire.
 * @return Un tableau de chaînes contenant les sous-chaînes extraites.
 */
static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2)
			return (0);
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

/**
 * @brief Sépare une chaîne de caractères en mots en fonction d'un 
 *        caractère délimiteur et retourne un tableau de chaînes.
 * 
 * @param s La chaîne à découper.
 * @param c Le caractère séparateur.
 * @return Un tableau contenant les mots extraits ou NULL en cas d'erreur.
 */
char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	ft_split_words(s, c, s2, num_words);
	return (s2);
}
