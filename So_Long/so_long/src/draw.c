/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:22:24 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:32:26 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Dessine un carré d'une image sur une position donnée dans la fenêtre.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param img Image source contenant les pixels à dessiner.
 * @param x Coordonnée X où le carré sera dessiné.
 * @param y Coordonnée Y où le carré sera dessiné.
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
 * @brief Dessine les éléments interactifs (joueur, objets, sortie) sur la carte.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param i Coordonnée X dans la grille de la carte.
 * @param j Coordonnée Y dans la grille de la carte.
 */
static void	draw_env(t_root *root, int i, int j)
{
	int				k;

	if (root->game->exit.x == i && root->game->exit.y == j)
		draw_square(root, root->exit, i * 40, j * 40);
	k = -1;
	while (++k < root->game->count_coll)
		if (root->game->coll[k].x == i && root->game->coll[k].y == j)
			draw_square(root, root->coll, i * 40, j * 40);
	if (root->game->player.x == i && root->game->player.y == j)
		draw_square(root, root->player, i * 40, j * 40);
}

/**
 * @brief Dessine la carte complète, y compris les murs, le sol, et les éléments
 *        interactifs.
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
