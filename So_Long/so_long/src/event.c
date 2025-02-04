/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 12:29:01 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:43:01 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Gère les événements de pression de touches pour le déplacement 
 *        du joueur ou pour quitter le jeu.
 *
 * @param keycode Code de la touche pressée.
 * @param root Structure principale contenant les données du jeu.
 * @return Retourne toujours 0.
 */
int	key_press(int keycode, t_root *root)
{
	if (keycode == 65307)
		root_destroy(root, 0, 0);
	if (keycode == 119 || keycode == 65362)
		root->game->player_up = 1;
	if (keycode == 115 || keycode == 65364)
		root->game->player_down = 1;
	if (keycode == 97 || keycode == 65361)
		root->game->player_left = 1;
	if (keycode == 100 || keycode == 65363)
		root->game->player_right = 1;
	update(root);
	return (0);
}

/**
 * @brief Gère les événements de relâchement de touches pour arrêter 
 *        le déplacement du joueur.
 *
 * @param keycode Code de la touche relâchée.
 * @param root Structure principale contenant les données du jeu.
 * @return Retourne toujours 0.
 */
int	key_release(int keycode, t_root *root)
{
	if (keycode == 119 || keycode == 65362)
		root->game->player_up = 0;
	if (keycode == 115 || keycode == 65364)
		root->game->player_down = 0;
	if (keycode == 97 || keycode == 65361)
		root->game->player_left = 0;
	if (keycode == 100 || keycode == 65363)
		root->game->player_right = 0;
	update(root);
	return (0);
}

/**
 * @brief Gère la destruction de la fenêtre MLX lorsque l'utilisateur 
 *        ferme la fenêtre ou interrompt le programme.
 *
 * @param keycode Code de la touche ou de l'événement (non utilisé ici).
 * @param root Structure principale contenant les données du jeu.
 * @return Retourne toujours 0.
 */
int	destroy_hook(int keycode, t_root *root)
{
	(void)keycode;
	(void)root;
	root_destroy(0, 0, 0);
	return (0);
}
