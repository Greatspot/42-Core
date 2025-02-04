/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:14:15 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:34:30 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Met à jour le compteur de mouvements si le joueur a changé de position.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param x Ancienne position X du joueur.
 * @param y Ancienne position Y du joueur.
 */
static void	had_move(t_root *root, int x, int y)
{
	if (root->game->player.x != x || root->game->player.y != y)
	{
		root->game->player_move++;
		ft_putnbr_fd(root->game->player_move, 1);
		ft_putendl_fd(" < Number of moves", 1);
	}
}

/**
 * @brief Vérifie si le joueur a ramassé un objet collectable et met à jour 
 *        les données du jeu.
 *
 * @param root Structure principale contenant les données du jeu.
 */
static void	iscollectable(t_root *root)
{
	int	k;

	k = 0;
	while (k < root->game->count_coll)
	{
		if (root->game->coll[k].x == root->game->player.x
			&& root->game->coll[k].y == root->game->player.y)
		{
			root->game->coll[k].x = -1;
			root->game->coll[k].y = -1;
			root->game->player_coll++;
		}
		k++;
	}
}

/**
 * @brief Met à jour la position du joueur, les collectables, et vérifie 
 *        les conditions de victoire.
 *
 * @param root Structure principale contenant les données du jeu.
 */
void	update(t_root *root)
{
	int	x;
	int	y;

	x = root->game->player.x;
	y = root->game->player.y;
	if (root->game->player_up != 0)
		move_up(root, x, y);
	else if (root->game->player_down != 0)
		move_down(root, x, y);
	else if (root->game->player_left != 0)
		move_left(root, x, y);
	else if (root->game->player_right != 0)
		move_right(root, x, y);
	had_move(root, x, y);
	iscollectable(root);
	draw(root);
	if (root->game->exit.x == root->game->player.x
		&& root->game->exit.y == root->game->player.y)
	{
		if (root->game->count_coll == root->game->player_coll)
			root_destroy(root, 0, 0);
	}
}
