/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:22:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:33:26 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Libère toutes les ressources allouées dans la structure root
 *        et termine le programme en affichant un message d'erreur
 *        si nécessaire.
 *
 * @param root Pointeur vers la structure principale à détruire.
 * @param errmsg Message d'erreur à afficher avant de quitter (peut être NULL).
 * @param errnum Code d'erreur à retourner au système (0 si aucun).
 */
void	root_destroy(t_root *root, char *errmsg, int errnum)
{
	if (root != 0)
	{
		if (root->ground != 0)
			mlx_destroy_image(root->mlx, root->ground);
		if (root->wall != 0)
			mlx_destroy_image(root->mlx, root->wall);
		if (root->coll != 0)
			mlx_destroy_image(root->mlx, root->coll);
		if (root->exit != 0)
			mlx_destroy_image(root->mlx, root->exit);
		if (root->player != 0)
			mlx_destroy_image(root->mlx, root->player);
		if (root->mlx_img != 0)
			mlx_destroy_image(root->mlx, root->mlx_img);
		if (root->mlx_win != 0)
			mlx_destroy_window(root->mlx, root->mlx_win);
		if (root->mlx != 0)
			mlx_destroy_display(root->mlx);
		if (root->game != 0)
			game_destroy(root->game);
		free(root);
	}
	die(errmsg, errnum);
}
