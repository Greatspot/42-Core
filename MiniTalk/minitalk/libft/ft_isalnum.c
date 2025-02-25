/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:52:31 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:47:12 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Analyse un caractère pour déterminer s'il s'agit d'une lettre ou d'un chiffre.
 * Cette fonction utilise les codes ASCII pour faire la distinction.
 *
 * @param c Caractère à analyser.
 * @return Retourne 1 si c'est une lettre ou un chiffre, sinon 0.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
