/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:22:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:31:16 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Combine le contenu actuel du fichier avec un nouveau buffer et gère
 *        les erreurs de mémoire.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Pointeur vers la chaîne contenant le contenu actuel du fichier.
 * @param buf Buffer contenant les nouvelles données à ajouter.
 * @param fd Descripteur de fichier ouvert pour le fichier de carte.
 */
static void	file_parse(t_root *root, char **file, char buf[], int fd)
{
	char			*tmp;

	tmp = ft_strjoin(*file, buf);
	if (!tmp)
		root_destroy(root, "map_init(): ft_strjoin() failed", errno);
	free(*file);
	*file = tmp;
	if (*file == NULL)
	{
		close(fd);
		root_destroy(root, "map_init(): ft_strjoin()", errno);
	}
}

/**
 * @brief Lit le fichier en utilisant des buffers et concatène les données
 *        dans une chaîne unique.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param file Pointeur vers la chaîne où stocker le contenu du fichier.
 * @param buf Buffer temporaire pour lire les données.
 * @param fd Descripteur de fichier ouvert pour le fichier de carte.
 */
static void	file_read(t_root *root, char **file, char buf[], int fd)
{
	int				ret;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, 1024);
		if (ret == -1)
		{
			free(*file);
			close(fd);
			root_destroy(root, "map_init(): read()", errno);
		}
		else
		{
			buf[ret] = 0;
			file_parse(root, file, buf, fd);
		}
	}
}

/**
 * @brief Initialise une chaîne vide pour stocker le contenu du fichier.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param fd Descripteur de fichier ouvert pour le fichier de carte.
 * @return Pointeur vers une chaîne allouée initialement vide.
 */
static char	*file_init(t_root *root, int fd)
{
	char			*file;

	file = ft_calloc(1, 1);
	if (!file)
	{
		close(fd);
		root_destroy(root, "map_init(): ft_calloc() failed", errno);
	}
	return (file);
}

/**
 * @brief Initialise la carte en lisant et en analysant un fichier donné.
 *
 * @param root Structure principale contenant les données du jeu.
 * @param filename Nom du fichier contenant la carte.
 */
void	map_init(t_root *root, char *filename)
{
	int				fd;
	char			*file;
	char			buf[1024 + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		root_destroy(root, filename, errno);
	file = file_init(root, fd);
	file_read(root, &file, buf, fd);
	close(fd);
	map_read(root, file);
	free(file);
}
