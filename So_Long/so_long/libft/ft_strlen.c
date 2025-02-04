/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:48:36 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/23 17:48:37 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calcule la longueur de la chaîne fournie.
 *
 * @param s Chaîne dont on souhaite connaître la taille.
 * @return Renvoie la taille de la chaîne, ou génère une faute de segmentation
 * si le pointeur est null.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
