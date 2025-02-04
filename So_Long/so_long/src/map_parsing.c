/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 11:22:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:31:38 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Libère la mémoire allouée pour la matrice de la carte et termine le 
 *        programme en cas d'erreur d'allocation.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Chaîne contenant le contenu brut de la carte.
 * @param m Matrice de la carte à libérer.
 * @param size Nombre de lignes déjà allouées dans la matrice.
 */
static void	free_matrix(t_root *root, char *file, int **m, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	root->game->map = 0;
	free(file);
	root_destroy(root, "map_parsing(): malloc()", errno);
}

/**
 * @brief Récupère les coordonnées des objets spécifiques (joueur, sortie, 
 *        collectables) dans le fichier brut et met à jour leurs positions.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Chaîne contenant le contenu brut de la carte.
 * @param k Index actuel dans le fichier brut.
 * @param obj Compteur d'objets collectables trouvés.
 */
static void	get_coord(t_root *root, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		root->game->player.x = k % (root->game->width + 1);
		root->game->player.y = k / (root->game->width + 1);
		file[k] = '0';
	}
	if (file[k] == 'E')
	{
		root->game->exit.x = k % (root->game->width + 1);
		root->game->exit.y = k / (root->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		root->game->coll[*obj].x = k % (root->game->width + 1);
		root->game->coll[*obj].y = k / (root->game->width + 1);
		file[k] = '0';
		(*obj)++;
	}
}

/**
 * @brief Analyse le contenu brut de la carte, initialise la matrice de la 
 *        carte et récupère les coordonnées des objets du jeu.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Chaîne contenant le contenu brut de la carte.
 */
void	map_parsing(t_root *root, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < root->game->height)
	{
		root->game->map[j] = (int *)malloc(sizeof(int) * root->game->width);
		if (root->game->map[j] == 0)
			free_matrix(root, file, root->game->map, j);
		i = 0;
		while (i < root->game->width)
		{
			get_coord(root, file, k, &obj);
			root->game->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}
