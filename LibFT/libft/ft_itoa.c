/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:39:18 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:50:27 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/**
 * Compte le nombre de chiffres dans un entier donné.
 *
 * @param n Nombre entier dont on veut compter les chiffres.
 * @return Renvoie le nombre total de chiffres. Si le nombre
 * est négatif, ajoute 1 au total pour inclure le signe moins.
 */

static unsigned int	ft_digit_count(int n)
{
	unsigned int	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

/**
 * Transforme un nombre entier en une chaîne de caractères terminée par un null.
 *
 * @param n Nombre entier à convertir en chaîne.
 * @return Renvoie le nombre sous forme de chaîne de caractères,
 * ou NULL si l'allocation de mémoire échoue.
 */

char	*ft_itoa(int n)
{
	long			nbr;
	char			*itoa;
	unsigned int	digit_count;

	nbr = n;
	digit_count = ft_digit_count(n);
	itoa = (char *)malloc((digit_count + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[digit_count--] = '\0';
	if (n < 0)
	{
		nbr = -nbr;
		itoa[0] = '-';
	}
	if (nbr == 0)
		itoa[0] = '0';
	while (nbr)
	{
		itoa[digit_count--] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (itoa);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(10));
	return (0);
}
*/