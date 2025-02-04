/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 10:22:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-01-26 12:32:47 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Récupère la valeur d'un pixel dans une image MLX.
 *
 * @param img Pointeur vers la structure de l'image MLX.
 * @param x Coordonnée X du pixel.
 * @param y Coordonnée Y du pixel.
 * @return La valeur couleur du pixel (en format entier).
 */
unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

/**
 * @brief Dessine un pixel à une position spécifique dans une image MLX.
 *
 * @param mlx_img Pointeur vers la structure de l'image MLX.
 * @param x Coordonnée X où dessiner le pixel.
 * @param y Coordonnée Y où dessiner le pixel.
 * @param color Valeur couleur du pixel à dessiner (en format entier).
 */
void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

/**
 * @brief Convertit des valeurs RGBA en un entier couleur pour MLX.
 *
 * @param o Opacité (alpha), entre 0 et 255.
 * @param r Composante rouge, entre 0 et 255.
 * @param g Composante verte, entre 0 et 255.
 * @param b Composante bleue, entre 0 et 255.
 * @return La valeur couleur (en format entier) combinant RGBA.
 */
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}
