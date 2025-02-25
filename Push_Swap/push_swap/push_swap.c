/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 15:03:02 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 18:02:26 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

/**
 * @brief Initialise une pile en utilisant les arguments de la ligne de commande.
 *        Crée un nœud pour chaque argument et l'ajoute à la pile.
 *        Si les arguments sont passés sous forme d'une seule chaîne, 
 *        ils sont d'abord séparés. Ensuite, un index est assigné 
 *        à chaque nœud de la pile.
 * 
 * @param stack Pointeur vers la pile à initialiser.
 * @param argc Nombre d'arguments passés au programme.
 * @param argv Tableau contenant les arguments.
 */
static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
	{
		free_string(args);
	}
}

/**
 * @brief Trie la pile en fonction de sa taille.
 * Utilise l'algorithme de tri simple pour les petites piles (≤ 5 éléments),
 * sinon applique le tri radix pour les grandes piles.
 * 
 * @param stack_a Pointeur vers la pile principale.
 * @param stack_b Pointeur vers la pile auxiliaire.
 */
static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

/**
 * @brief Programme principal qui prend des entiers en entrée et 
 *        les trie en utilisant une structure de pile.
 *        Vérifie les arguments, initialise les piles, exécute le tri 
 *        et libère la mémoire avant de terminer.
 * 
 * @param argc Nombre d'arguments passés au programme.
 * @param argv Tableau contenant les arguments.
 * @return 0 en cas de succès, -1 si une erreur se produit.
 */
int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a) == 1)
		exit (EXIT_SUCCESS);
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_b = NULL;
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
