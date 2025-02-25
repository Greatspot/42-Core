/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 15:03:02 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 17:54:24 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Vérifie si un entier donné est présent dans un tableau de chaînes.
 *        Retourne 1 si le nombre est présent, sinon 0.
 * 
 * @param num L'entier à rechercher.
 * @param argv Tableau de chaînes contenant les arguments.
 * @param i L'index à partir duquel commencer la recherche.
 * @return 1 si le nombre est trouvé, sinon 0.
 */
static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Vérifie si une chaîne de caractères représente un nombre entier valide.
 * 
 * @param num La chaîne de caractères à vérifier.
 * @return 1 si c'est un nombre valide, sinon 0.
 */
static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
	}
	if ((num[0] == '-' || num[0] == '+') && !num[1])
	{
		return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * @brief Sépare une chaîne d'arguments unique en plusieurs sous-chaînes
 *        en utilisant l'espace comme délimiteur.
 * 
 * @param av La chaîne d'arguments à séparer.
 * @return Un tableau de chaînes résultant de la séparation.
 */
static char	**argc2(char *av)
{
	char	**args;

	args = ft_split(av, ' ');
	return (args);
}

/**
 * @brief Vérifie la validité des arguments passés au programme.
 *        Les nombres doivent être des entiers valides, sans doublons,
 *        et être dans la plage d'un type int.
 *        Gère également le cas où les arguments sont passés sous 
 *        forme d'une seule chaîne séparée par des espaces.
 * 
 * @param argc Nombre d'arguments.
 * @param argv Tableau des arguments passés en ligne de commande.
 */
void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 1;
	if (argc == 2)
		args = argc2(argv[1]);
	else
		args = argv;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			error_message("Error");
		if (ft_contains(tmp, args, i) == 1)
			error_message("Error");
		if (tmp < INT_MIN || tmp > 2147483647)
			error_message("Error");
		i++;
	}
	if (argc == 2)
		free_string(args);
}
