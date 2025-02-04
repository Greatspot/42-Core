/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:17:56 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:29:55 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Initialise la structure du jeu en allouant la mémoire nécessaire
 *        et en initialisant toutes les variables à des valeurs par défaut.
 *        Ensuite, initialise la carte à partir du fichier donné.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param filename Nom du fichier contenant la carte à charger.
 */
void	game_init(t_root *root, char *filename)
{
	root->game = (t_game *)malloc(sizeof(t_game));
	if (root->game == 0)
		root_destroy(root, "game_init(): malloc()", errno);
	root->game->map = 0;
	root->game->coll = 0;
	root->game->count_coll = 0;
	root->game->enemy = 0;
	root->game->count_enemy = 0;
	root->game->count_exit = 0;
	root->game->count_player = 0;
	root->game->player_move = 0;
	root->game->player_coll = 0;
	root->game->player_up = 0;
	root->game->player_down = 0;
	root->game->player_left = 0;
	root->game->player_right = 0;
	map_init(root, filename);
}
