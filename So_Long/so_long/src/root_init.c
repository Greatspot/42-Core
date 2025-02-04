/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:22:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:33:37 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Charge une texture XPM et met à jour ses dimensions.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param img Pointeur vers l'image à charger.
 * @param path Chemin vers le fichier de texture XPM.
 */
static void	texture_load(t_root *root, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	if (*img == 0)
		root_destroy(0, "texture_init(): can't load texture!", 0);
	(*img)->width = width;
	(*img)->height = height;
}

/**
 * @brief Initialise toutes les textures nécessaires au jeu.
 *
 * @param root Structure principale contenant les données du jeu.
 */
static void	texture_init(t_root *root)
{
	texture_load(root, &root->player, "./textures/player.xpm");
	texture_load(root, &root->exit, "./textures/house.xpm");
	texture_load(root, &root->coll, "./textures/pokeball.xpm");
	texture_load(root, &root->wall, "./textures/wall.xpm");
	texture_load(root, &root->ground, "./textures/sand.xpm");
}

/**
 * @brief Initialise les éléments du moteur de rendu (MLX).
 *
 * @param root Structure principale contenant les données du jeu.
 */
static void	renderer_init(t_root *root)
{
	root->mlx = mlx_init();
	if (root->mlx == 0)
		root_destroy(root, "mlx_init(): can't load mlx!", 0);
	root->mlx_win = mlx_new_window(root->mlx, root->game->width * 40,
			root->game->height * 40, "so_long");
	if (root->mlx_win == 0)
		root_destroy(root, "mlx_new_window(): can't create a window!", 0);
	root->mlx_img = mlx_new_image(root->mlx, root->game->width * 40,
			root->game->height * 40);
	if (root->mlx_img == 0)
		root_destroy(root, "mlx_new_image(): can't create an image!", 0);
}

/**
 * @brief Initialise la structure principale du jeu.
 *
 * @param filename Nom du fichier de la carte à charger.
 * @return Pointeur vers la structure initialisée.
 */
t_root	*root_init(char *filename)
{
	t_root			*root;

	root = (t_root *)malloc(sizeof(t_root));
	if (root == 0)
		root_destroy(0, "root_init(): malloc()", errno);
	root->game = 0;
	root->mlx = 0;
	root->mlx_win = 0;
	root->mlx_img = 0;
	root->player = 0;
	root->exit = 0;
	root->coll = 0;
	root->wall = 0;
	root->ground = 0;
	game_init(root, filename);
	renderer_init(root);
	texture_init(root);
	return (root);
}
