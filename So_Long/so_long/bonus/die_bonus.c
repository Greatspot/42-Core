/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:33:43 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/24 21:33:43 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
/**
 * @brief Affiche un message d'erreur et termine le programme.
 *
 * @param errmsg Message d'erreur à afficher, ou NULL si aucun.
 * @param errnum Code d'erreur à afficher, ou 0 si aucun.
 */

void	die(char *errmsg, int errnum)
{
	if (errmsg != NULL || errnum != 0)
		ft_putendl_fd("Error!", 2);
	if (errmsg != NULL)
		ft_putstr_fd(errmsg, 2);
	if (errmsg != NULL && errnum != 0)
		ft_putstr_fd(": ", 2);
	if (errnum != 0)
		ft_putstr_fd(strerror(errnum), 2);
	if (errmsg != NULL || errnum != 0)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}
