/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:29:19 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/04 21:49:18 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Imprime un entier en hexadécimal (minuscule ou majuscule).
 *
 * @param n Entier à convertir.
 * @param base Base hexadécimale en minuscule ou majuscule.
 * @return Nombre de caractères imprimés.
 */

static int	ft_putnbr_hex(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}
/**
 * @brief Sélectionne la base hexadécimale appropriée et imprime l'entier.
 *
 * @param n Entier à imprimer.
 * @param format Format pour déterminer minuscule ('x') ou majuscule ('X').
 * @return Nombre de caractères imprimés.
 */

int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_putnbr_hex(n, "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_hex(n, "0123456789ABCDEF"));
	return (0);
}
