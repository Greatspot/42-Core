/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:33:30 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/24 21:33:30 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Vérifie si le joueur s'est déplacé, met à jour le compteur de 
 *        mouvements, et l'affiche dans la fenêtre du jeu.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param x Ancienne position X du joueur.
 * @param y Ancienne position Y du joueur.
 */
static void	had_move(t_root *root, int x, int y)
{
	char	*mvs;

	if (root)
	{
		if (root->game->player.x != x || root->game->player.y != y)
		{
			root->game->player_move++;
			mvs = ft_itoa(root->game->player_move);
			if (mvs == NULL)
				root_destroy(root, "Error allocating memory in ft_itoa", errno);
			mlx_clear_window(root->mlx, root->mlx_win);
			mlx_string_put(root->mlx, root->mlx_win, root->game->width * 40.5,
				root->game->height * 5, 0x00FF0000, "Moves: ");
			mlx_string_put(root->mlx, root->mlx_win, root->game->width * 44,
				root->game->height * 5, 0x00FFFFFF, mvs);
			free(mvs);
		}
	}
}

/**
 * @brief Vérifie si le joueur a ramassé un objet collectable et met à jour
 *        les données correspondantes.
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
 * @brief Vérifie si le joueur a touché un ennemi et termine le jeu en cas
 *        de collision.
 *
 * @param root Structure principale contenant les données du jeu.
 */
static void	isenemy(t_root *root)
{
	int	z;

	z = 0;
	while (z < root->game->count_enemy)
	{
		if (root->game->enemy[z].x == root->game->player.x
			&& root->game->enemy[z].y == root->game->player.y)
		{
			ft_putstr_fd("You touched an enemy.\n", 1);
			ft_putstr_fd("Try again.\n", 1);
			root_destroy(root, 0, 0);
		}
		z++;
	}
}

/**
 * @brief Vérifie si le joueur a atteint la sortie et termine le jeu si
 *        toutes les conditions de victoire sont remplies.
 *
 * @param root Structure principale contenant les données du jeu.
 */
static void	exit_anim(t_root *root)
{
	if (root->game->exit.x == root->game->player.x
		&& root->game->exit.y == root->game->player.y)
	{
		if (root->game->count_coll == root->game->player_coll)
		{
			ft_putstr_fd("You win!\n", 1);
			root_destroy(root, 0, 0);
		}
	}
}

/**
 * @brief Met à jour l'état du jeu en fonction des actions du joueur, vérifie
 *        les collisions, et redessine l'écran.
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
	isenemy(root);
	exit_anim(root);
}
