/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:17:49 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:48:29 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Vérifie si un caractère représente un chiffre, entre 0 et 9.
 * La vérification s’effectue par comparaison des codes ASCII.
 *
 * @param c Caractère à examiner.
 * @return 1 si le caractère est un chiffre, sinon 0.
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
