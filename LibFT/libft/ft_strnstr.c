/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:15 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 19:08:26 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Recherche une sous-chaîne (aiguille/petite) 
 * dans une autre chaîne (botte de foin/grande).
 *
 * @param big Chaîne dans laquelle chercher la sous-chaîne (botte de foin).
 * @param little Sous-chaîne à rechercher dans big (aiguille).
 * @param len Nombre de bytes à parcourir dans big.
 * @return Renvoie un pointeur vers la première occurrence de little dans big.
 * Si la longueur de little est 0, renvoie big.
 * Si little n'est pas trouvé, renvoie NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && i + j < len && big[i + j] == little[j])
				j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s", ft_substr("Hello World!", 6, 6));
	return (0);
}
*/