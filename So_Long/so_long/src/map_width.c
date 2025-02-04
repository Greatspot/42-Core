/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:28:08 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:32:27 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Calcule la largeur de la carte en comptant les caractères jusqu'à 
 *        la première nouvelle ligne ou la fin du fichier.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Chaîne contenant le contenu brut de la carte.
 */
void	map_width(t_root *root, char *file)
{
	root->game->width = 0;
	while (file[root->game->width] && file[root->game->width] != '\n')
		root->game->width++;
	if (root->game->width == 0 || file[root->game->width] == 0)
	{
		free(file);
		root_destroy(root, "Map is invalid!", 0);
	}
}
