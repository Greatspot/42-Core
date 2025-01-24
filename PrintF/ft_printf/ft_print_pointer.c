/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:28:23 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/12/04 21:35:21 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Imprime un nombre en format hexadécimal (utilisé pour les pointeurs).
 *
 * @param num Nombre à convertir en hexadécimal.
 * @return Nombre de caractères imprimés.
 */
static int	ft_put_hex(unsigned long long num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_put_hex(num / 16);
	count += write(1, &base[num % 16], 1);
	return (count);
}

/**
 * @brief Imprime un pointeur en format hexadécimal avec le préfixe "0x".
 *
 * @param ptr Pointeur à imprimer.
 * @return Nombre de caractères imprimés.
 */
int	ft_print_pointer(void *ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5)); // Imprime "(nil)" pour un pointeur NULL.
	count = write(1, "0x", 2);        // Préfixe obligatoire.
	count += ft_put_hex((unsigned long long)ptr);
	return (count);
}
