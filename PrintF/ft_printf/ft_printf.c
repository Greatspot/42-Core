/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:25:49 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/04 21:35:46 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Sélectionne et appelle la fonction appropriée pour chaque conversion.
 *
 * @param c Caractère représentant le format de conversion.
 * @param args Liste d'arguments variadiques.
 * @return Nombre de caractères imprimés pour cette conversion.
 */

static int	handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_print_percent());
	return (0);
}

/**
 * @brief Fonction principale pour imiter printf.
 *
 * @param format Chaîne de format contenant les spécificateurs.
 * @return Nombre total de caractères imprimés.
 */

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += handle_format(format[++i], args);
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
