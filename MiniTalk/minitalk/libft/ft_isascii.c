/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:53:10 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:47:58 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Vérifie si un caractère fait partie de la table ASCII standard.
 * Cette vérification est faite en comparant les codes ASCII.
 *
 * @param c Caractère à tester.
 * @return 1 si le caractère est dans la table ASCII, sinon 0.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
