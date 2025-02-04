/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:34:04 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:29:52 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Gère les événements de pression de touches pour déplacer le joueur 
 *        ou quitter le jeu.
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
 * @brief Gère les événements de relâchement de touches, arrêtant les 
 *        mouvements du joueur.
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
 * @brief Gère la fermeture de la fenêtre du jeu lorsqu'un événement de 
 *        destruction est détecté.
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
