/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:52:43 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:47:39 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Identifie si un caractère est une lettre majuscule ou minuscule.
 * Compare directement les valeurs ASCII pour effectuer cette vérification.
 *
 * @param c Caractère à analyser.
 * @return 1 si c'est une lettre, sinon 0.
 */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
