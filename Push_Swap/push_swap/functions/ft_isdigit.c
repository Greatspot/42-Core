/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 08:01:59 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 10:08:40 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Vérifie si un caractère donné est un chiffre (0-9).
 *        Retourne 1 si c'est un chiffre, sinon retourne 0.
 * 
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est un chiffre, 0 sinon.
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
