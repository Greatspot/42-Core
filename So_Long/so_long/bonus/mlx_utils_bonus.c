/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 12:23:16 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 13:24:18 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Récupère la valeur d'un pixel à une position donnée dans une image MLX.
 *
 * @param img Pointeur vers la structure de l'image MLX.
 * @param x Coordonnée X du pixel.
 * @param y Coordonnée Y du pixel.
 * @return La couleur du pixel en format entier.
 */
unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

/**
 * @brief Dessine un pixel à une position spécifique dans une image MLX.
 *
 * @param mlx_img Pointeur vers la structure de l'image MLX où dessiner.
 * @param x Coordonnée X où le pixel sera dessiné.
 * @param y Coordonnée Y où le pixel sera dessiné.
 * @param color Couleur du pixel à dessiner en format entier.
 */
void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

/**
 * @brief Convertit des valeurs RGBA en une valeur entière utilisable par MLX.
 *
 * @param o Opacité (alpha), entre 0 et 255.
 * @param r Composante rouge, entre 0 et 255.
 * @param g Composante verte, entre 0 et 255.
 * @param b Composante bleue, entre 0 et 255.
 * @return Une couleur en format entier combinant RGBA.
 */
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}
