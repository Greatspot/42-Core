/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 11:21:39 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:21:39 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Vérifie si une position donnée est sur la bordure de la carte.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param i Index actuel dans le contenu brut de la carte.
 * @return 1 si l'index correspond à une bordure, 0 sinon.
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
 * @brief Valide le contenu d'une case spécifique de la carte et met à jour
 *        les compteurs d'objets (joueur, sortie, collectables, ennemis).
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Contenu brut de la carte.
 * @param i Index actuel dans le contenu de la carte.
 */
static void	isvalid(t_root *root, char *file, int i)
{
	if (file[i] == 'P')
		root->game->count_player++;
	else if (file[i] == 'E')
		root->game->count_exit++;
	else if (file[i] == 'C')
		root->game->count_coll++;
	else if (file[i] == 'N')
		root->game->count_enemy++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		root_destroy(root, "Map content is invalid!", 0);
	}
}

/**
 * @brief Vérifie si la configuration globale de la carte est valide
 *        (ex: un joueur, une sortie, au moins un collectable et un ennemi).
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Contenu brut de la carte.
 */
static void	istrue(t_root *root, char *file)
{
	if (root->game->count_player != 1
		|| root->game->count_exit != 1
		|| root->game->count_coll < 1
		|| root->game->count_enemy < 1)
	{
		free(file);
		root_destroy(root, "Map configuration is invalid!", 0);
	}
}

/**
 * @brief Valide la carte en vérifiant les bordures, le contenu des cases,
 *        et la configuration globale.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Contenu brut de la carte.
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
				root_destroy(root, "Map isn't surrounded by walls!", 0);
			}
		}
		else
			isvalid(root, file, i);
	}
	istrue(root, file);
}
