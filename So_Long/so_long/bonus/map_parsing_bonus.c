/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 12:22:24 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:23:44 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Libère la mémoire allouée pour une matrice de carte en cas
 *        d'erreur, puis quitte le programme.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Contenu brut de la carte à libérer.
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
 * @brief Récupère les coordonnées des objets essentiels du jeu (joueur, sortie,
 *        collectables) et met à jour leurs positions.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Contenu brut de la carte.
 * @param k Index actuel dans le contenu de la carte.
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
	else if (file[k] == 'E')
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
 * @brief Récupère les coordonnées des ennemis sur la carte et les stocke.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Contenu brut de la carte.
 * @param k Index actuel dans le contenu de la carte.
 * @param num Compteur d'ennemis trouvés.
 */
static void	get_enemy(t_root *root, char *file, int k, int *num)
{
	if (file[k] == 'N')
	{
		root->game->enemy[*num].x = k % (root->game->width + 1);
		root->game->enemy[*num].y = k / (root->game->width + 1);
		file[k] = '0';
		(*num)++;
	}
}

/**
 * @brief Analyse et initialise les données de la carte, y compris les
 *        collectables, les ennemis et la matrice de la carte.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Contenu brut de la carte.
 */
void	map_parsing(t_root *root, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;
	int				num;

	obj = 0;
	num = 0;
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
			get_enemy(root, file, k, &num);
			root->game->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}
