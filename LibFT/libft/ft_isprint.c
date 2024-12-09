/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:38:56 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:49:00 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Vérifie si un caractère est affichable à l'écran.
 * Cette vérification se fait en comparant les codes ASCII.
 *
 * @param c Caractère à vérifier.
 * @return 1 si le caractère est imprimable, sinon 0.
 */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
