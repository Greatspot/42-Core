/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:46:24 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:25:37 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Trouve la première occurrence d'un caractère dans une chaîne.
 *
 * @param str Chaîne dans laquelle chercher le caractère c.
 * @param c Caractère à localiser.
 * @return Renvoie un pointeur vers la première occurrence de c dans str,
 * ou null si c n'est pas trouvé. Si c est '\0', renvoie un pointeur
 * vers l'octet de terminaison null.
 */
char	*ft_strchr(const char *ptr, int c)
{
	while (*ptr)
	{
		if (*ptr == (char)c)
			return ((char *)ptr);
		ptr++;
	}
	if ((char)c == '\0')
		return ((char *)ptr);
	return (NULL);
}
