/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:57:50 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:32:50 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Transforme une lettre en minuscule si une équivalence existe.
 *
 * @param c Lettre à convertir en minuscule.
 * @return Renvoie la lettre en minuscule si possible,
 * ou c si la conversion n'est pas applicable.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
