/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:30:26 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 13:19:11 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Extrait un nombre entier à partir d'une chaîne contenant un nombre.
 *
 * @param nptr Chaîne contenant le nombre.
 * @return Renvoie le nombre extrait ou 0 si la chaîne est invalide.
 */
int ft_atoi(const char *nptr)
{
	int number;
	int sign_multiplier;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign_multiplier = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign_multiplier *= -1;
		nptr++;
	}
	number = 0;
	while (ft_isdigit(*nptr))
	{
		number = number * 10 + (*nptr - '0');
		nptr++;
	}
	return (number * sign_multiplier);
}
