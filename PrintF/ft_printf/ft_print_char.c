/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:27:49 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/04 21:37:44 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

/**
 * @brief Imprime un seul caractère.
 *
 * @param c Caractère à imprimer.
 * @return Nombre de caractères imprimés (1).
 */

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}
