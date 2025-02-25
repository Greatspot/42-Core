/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 15:37:43 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 10:16:50 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Trie une pile contenant quatre éléments. Cette fonction identifie 
 *        la position de l'élément le plus petit, le déplace au sommet, 
 *        puis l'envoie à une pile temporaire avant de trier les trois 
 *        éléments restants avec la fonction sort_3.
 *
 * @param stack_a Pointeur vers la pile principale.
 * @param stack_b Pointeur vers la pile temporaire.
 */
void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = index_distance_head(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

/**
 * @brief Trie une pile contenant cinq éléments. Cette fonction identifie 
 *        et déplace les deux éléments les plus petits vers une pile 
 *        temporaire, trie les trois éléments restants avec sort_4, 
 *        puis réinsère les deux éléments dans la pile principale.
 *
 * @param stack_a Pointeur vers la pile principale.
 * @param stack_b Pointeur vers la pile temporaire.
 */
void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = index_distance_head(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/**
 * @brief Trie une pile de taille 2 à 5 en appelant des fonctions 
 *        de tri spécifiques. Si la pile est déjà triée ou contient 
 *        moins de deux éléments, aucune opération n'est effectuée.
 *
 * @param stack_a Pointeur vers la pile principale.
 * @param stack_b Pointeur vers la pile temporaire.
 */
void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
