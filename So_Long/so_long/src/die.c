/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 12:10:55 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:27:50 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Affiche un message d'erreur détaillé et quitte le programme.
 *
 * @param errmsg Message d'erreur personnalisé à afficher (peut être NULL).
 * @param errnum Code d'erreur du système (0 si aucun).
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
