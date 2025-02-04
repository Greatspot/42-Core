/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 17:46:30 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 20:13:55 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Lit et analyse les données de la carte, initialise les dimensions,
 *        vérifie sa validité, et alloue la mémoire pour les collectables,
 *        ennemis et la matrice de la carte.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Chaîne contenant le contenu brut de la carte.
 */
void	map_read(t_root *root, char *file)
{
	map_width(root, file);
	map_height(root, file);
	map_isvalid(root, file);
	root->game->coll
		= (t_coord *)malloc(sizeof(t_coord) * root->game->count_coll);
	root->game->enemy
		= (t_coord *)malloc(sizeof(t_coord) * root->game->count_enemy);
	if (root->game->coll == 0 || root->game->enemy == 0)
	{
		free(file);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	if (root->game->map == 0)
	{
		free(file);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	map_parsing(root, file);
}
