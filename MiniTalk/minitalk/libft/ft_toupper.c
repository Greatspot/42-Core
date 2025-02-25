/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:59 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:33:07 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Transforme une lettre en majuscule si une équivalence existe.
 *
 * @param c Lettre à convertir en majuscule.
 * @return Renvoie la lettre en majuscule si possible,
 * ou c si la conversion n'est pas applicable.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
