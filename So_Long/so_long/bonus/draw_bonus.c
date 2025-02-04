/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:33:54 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:35:35 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Dessine un carré d'une image sur la fenêtre du jeu.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param img Image source contenant les pixels à dessiner.
 * @param x Position X où dessiner le carré.
 * @param y Position Y où dessiner le carré.
 */
static void	draw_square(t_root *root, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(root->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

/**
 * @brief Dessine les éléments interactifs (joueur, ennemis, objets).
 *
 * @param root Structure principale contenant les données du jeu.
 * @param i Position X dans la grille du jeu.
 * @param j Position Y dans la grille du jeu.
 */
static void	draw_env(t_root *root, int i, int j)
{
	int				k;
	int				z;

	if (root->game->exit.x == i && root->game->exit.y == j
		&& root->game->count_coll == root->game->player_coll)
		draw_square(root, root->exit, i * 40, j * 40);
	k = -1;
	while (++k < root->game->count_coll)
		if (root->game->coll[k].x == i && root->game->coll[k].y == j)
			draw_square(root, root->coll, i * 40, j * 40);
	z = -1;
	while (++z < root->game->count_enemy)
		if (root->game->enemy[z].x == i && root->game->enemy[z].y == j)
			draw_square(root, root->enemy, i * 40, j * 40);
	if (root->game->player.x == i && root->game->player.y == j)
		draw_square(root, root->player, i * 40, j * 40);
}

/**
 * @brief Dessine la carte complète (murs, sol) et les éléments du jeu.
 *
 * @param root Structure principale contenant les données du jeu.
 */
static void	draw_map(t_root *root)
{
	int				i;
	int				j;

	j = 0;
	while (j < root->game->height)
	{
		i = 0;
		while (i < root->game->width)
		{
			if (root->game->map[j][i] == 1)
				draw_square(root, root->wall, i * 40, j * 40);
			else
				draw_square(root, root->ground, i * 40, j * 40);
			draw_env(root, i, j);
			i++;
		}
		j++;
	}
}

/**
 * @brief Point d'entrée pour dessiner la carte et afficher la fenêtre.
 *
 * @param root Structure principale contenant les données du jeu.
 */
void	draw(t_root *root)
{
	draw_map(root);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
}
