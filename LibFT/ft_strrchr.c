/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:28 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:31:19 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Trouve la dernière occurrence d'un caractère dans une chaîne.
 *
 * @param str Chaîne dans laquelle rechercher le caractère c.
 * @param c Caractère à localiser.
 * @return Renvoie un pointeur vers la dernière occurrence de c dans str,
 * ou null si c n'est pas trouvé. Si c est '\0', renvoie un pointeur
 * vers l'octet de terminaison null.
 */
char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occur;

	last_occur = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			last_occur = str;
		str++;
	}
	if (!c)
		return ((char *)str);
	return ((char *)last_occur);
}
