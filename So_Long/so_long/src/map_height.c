/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 13:36:42 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:30:39 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/**
 * @brief Calcule la hauteur de la carte en comptant les lignes et vérifie 
 *        que toutes les lignes ont la même largeur.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Chaîne contenant le contenu brut de la carte.
 */
void	map_height(t_root *root, char *file)
{
	int				i;
	int				j;

	root->game->height = 1;
	i = root->game->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (root->game->width != j)
		{
			free(file);
			root_destroy(root, "Map is invalid!", 0);
		}
		i += root->game->width + 1;
		root->game->height++;
	}
}
