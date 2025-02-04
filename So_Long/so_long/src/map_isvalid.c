/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:24:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:31:26 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Vérifie si une position donnée est sur une bordure de la carte.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param i Index actuel dans le contenu brut de la carte.
 * @return 1 si l'index est une bordure, 0 sinon.
 */
static int	isborder(t_root *root, int i)
{
	if (i < root->game->width
		|| i > (root->game->width + 1) * (root->game->height - 1)
		|| i % (root->game->width + 1) == 0
		|| i % (root->game->width + 1) == root->game->width - 1)
		return (1);
	return (0);
}

/**
 * @brief Vérifie si un caractère dans la carte est valide et met à jour les
 *        compteurs d'objets.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Chaîne contenant le contenu brut de la carte.
 * @param i Index actuel dans le contenu brut de la carte.
 */
static void	isvalid(t_root *root, char *file, int i)
{
	if (file[i] == 'P')
		root->game->count_player++;
	else if (file[i] == 'E')
		root->game->count_exit++;
	else if (file[i] == 'C')
		root->game->count_coll++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		root_destroy(root, "Map is invalid!", 0);
	}
}

/**
 * @brief Valide la structure et le contenu de la carte. Vérifie les bordures, 
 *        les caractères, et les compteurs d'objets essentiels.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Chaîne contenant le contenu brut de la carte.
 */
void	map_isvalid(t_root *root, char *file)
{
	int				i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (isborder(root, i))
		{
			if (file[i] != '1')
			{
				free(file);
				root_destroy(root, "Map needs to be surrounded by walls.", 0);
			}
		}
		else
			isvalid(root, file, i);
	}
	if (root->game->count_player != 1
		|| root->game->count_exit != 1
		|| root->game->count_coll < 1)
	{
		free(file);
		root_destroy(root, "Map is invalid!", 0);
	}
}
