/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 20:39:56 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:29:55 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Calcule la largeur de la carte en comptant les caractères
 *        jusqu'à la première nouvelle ligne.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Contenu brut du fichier de la carte.
 */
void	map_width(t_root *root, char *file)
{
	root->game->width = 0;
	while (file[root->game->width] && file[root->game->width] != '\n')
		root->game->width++;
	if (root->game->width == 0 || file[root->game->width] == 0)
	{
		free(file);
		root_destroy(root, "Map file is invalid!", 0);
	}
}
