/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:31:27 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/04 21:38:28 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Imprime le caractère de pourcentage '%'.
 *
 * @return Nombre de caractères imprimés (1).
 */

int	ft_print_percent(void)
{
	return (write(1, "%", 1));
}
