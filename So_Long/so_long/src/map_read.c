/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:28:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:31:58 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Lit et analyse les données de la carte à partir du contenu brut du 
 *        fichier. Initialise les dimensions de la carte, vérifie sa validité 
 *        et alloue la mémoire nécessaire.
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
	if (root->game->coll == 0)
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
