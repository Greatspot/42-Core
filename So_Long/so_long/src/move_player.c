/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:22:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:33:10 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Déplace le joueur vers le haut si la case au-dessus est accessible.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param x Position X actuelle du joueur.
 * @param y Position Y actuelle du joueur.
 */
void	move_up(t_root *root, int x, int y)
{
	if (root->game->map[y - 1][x] == 0)
		root->game->player.y -= 1;
}

/**
 * @brief Déplace le joueur vers le bas si la case en dessous est accessible.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param x Position X actuelle du joueur.
 * @param y Position Y actuelle du joueur.
 */
void	move_down(t_root *root, int x, int y)
{
	if (root->game->map[y + 1][x] == 0)
		root->game->player.y += 1;
}

/**
 * @brief Déplace le joueur vers la gauche si la case à gauche est accessible.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param x Position X actuelle du joueur.
 * @param y Position Y actuelle du joueur.
 */
void	move_left(t_root *root, int x, int y)
{
	if (root->game->map[y][x - 1] == 0)
		root->game->player.x -= 1;
}

/**
 * @brief Déplace le joueur vers la droite si la case à droite est accessible.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param x Position X actuelle du joueur.
 * @param y Position Y actuelle du joueur.
 */
void	move_right(t_root *root, int x, int y)
{
	if (root->game->map[y][x + 1] == 0)
		root->game->player.x += 1;
}
