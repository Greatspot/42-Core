/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:22:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:33:46 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Vérifie si le fichier donné a l'extension ".ber".
 *
 * @param file Nom du fichier à vérifier.
 * @return 1 si le fichier a l'extension ".ber", 0 sinon.
 */
int	isber(char *file)
{
	int	len;

	if (file == NULL)
		return (0);
	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

/**
 * @brief Point d'entrée principal du programme. Initialise les structures 
 *        du jeu, vérifie les arguments et lance la boucle principale.
 *
 * @param ac Nombre d'arguments passés au programme.
 * @param av Tableau contenant les arguments.
 * @return 0 si le programme se termine correctement.
 */
int	main(int ac, char *av[])
{
	t_root	*root;

	if (ac != 2)
		die("Invalid number of arguments!", 0);
	if (isber(av[1]) == 0)
		die("Invalid argument! (<name>.ber)", 0);
	root = root_init(av[1]);
	draw(root);
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, key_release, root);
	mlx_hook(root->mlx_win, 17, 1L << 17, destroy_hook, root);
	mlx_loop(root->mlx);
	return (0);
}
