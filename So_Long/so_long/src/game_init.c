/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:45:15 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:30:17 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialise la structure du jeu en allouant la mémoire nécessaire 
 *        et en initialisant les variables par défaut. Ensuite, lit et analyse 
 *        la carte du fichier donné.
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
