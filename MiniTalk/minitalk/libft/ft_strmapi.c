/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:55 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:30:08 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Génère une copie de la chaîne donnée, en appliquant
 * la fonction f à chaque caractère.
 *
 * @param s Chaîne à transformer.
 * @param f Fonction à appliquer sur chaque caractère.
 * @return Renvoie une nouvelle chaîne allouée avec chaque 
 * caractère modifié par f.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;

	if (!f || !s)
		return (NULL);
	mapi = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!mapi)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
