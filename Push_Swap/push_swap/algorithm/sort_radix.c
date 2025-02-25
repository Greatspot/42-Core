/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 15:31:54 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 10:15:50 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Calcule le nombre de bits nécessaires pour représenter 
 *        l'élément le plus grand dans une pile. La fonction parcourt 
 *        la pile pour trouver le plus grand index et calcule le 
 *        nombre de bits nécessaires pour le représenter.
 *
 * @param stack Pointeur vers la pile (liste chaînée).
 * @return Nombre de bits nécessaires.
 */
static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/**
 * @brief Trie une pile à l'aide de l'algorithme Radix. Les éléments 
 *        sont déplacés entre stack_a et stack_b en fonction des bits 
 *        significatifs de leurs index. Une fois le tri terminé, 
 *        tous les éléments sont replacés dans stack_a.
 *
 * @param stack_a Pointeur vers la pile principale à trier.
 * @param stack_b Pointeur vers la pile temporaire utilisée pour le tri.
 */
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (ft_lstsize(*stack_b) > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
