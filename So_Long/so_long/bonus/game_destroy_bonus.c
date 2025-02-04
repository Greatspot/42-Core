/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:34:10 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:29:55 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Libère toutes les ressources allouées pour la structure du jeu, y
 *        compris les collectables, les ennemis et la matrice de la carte.
 *
 * @param game Pointeur vers la structure du jeu à détruire.
 */
void	game_destroy(t_game *game)
{
	int				i;

	if (game != 0)
	{
		if (game->coll != 0)
			free(game->coll);
		if (game->enemy != 0)
			free(game->enemy);
		if (game->map != 0)
		{
			i = 0;
			while (i < game->height)
				free(game->map[i++]);
			free(game->map);
		}
		free(game);
	}
}
