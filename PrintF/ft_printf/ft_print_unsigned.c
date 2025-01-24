/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:29:04 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/04 21:37:02 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Imprime un entier non-signé.
 *
 * @param n Entier non-signé à imprimer.
 * @return Nombre de caractères imprimés.
 */

static int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	return (count + write(1, &c, 1));
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_putnbr_unsigned(n));
}
