/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:51:45 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:46:28 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Remplit une région mémoire avec des zéros, de manière similaire à memset.
 * @param s Pointeur vers la mémoire à remplir.
 * @param n Quantité d'octets à mettre à zéro.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
