/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 15:03:02 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 16:26:15 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

// LIBRARY
#include "../header/push_swap.h"

/**
 * @brief Effectue un échange entre les deux premiers éléments 
 *        d'une pile chaînée. Retourne -1 si la pile contient 
 *        moins de 2 éléments.
 * 
 * @param stack Pointeur vers la pile à modifier.
 * @return 0 si l'opération réussit, -1 sinon.
 */
static int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		error_message("Error");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

/**
 * @brief Effectue un échange entre les deux premiers éléments 
 *        de la pile A et affiche "sa" sur la sortie standard.
 * 
 * @param stack_a Pointeur vers la pile A.
 * @return 0 si l'opération réussit, -1 si la pile contient moins de 2 éléments.
 */
int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

/**
 * @brief Effectue un échange entre les deux premiers éléments 
 *        de la pile B et affiche "sb" sur la sortie standard.
 * 
 * @param stack_b Pointeur vers la pile B.
 * @return 0 si l'opération réussit, -1 si la pile contient moins de 2 éléments.
 */
int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

/**
 * @brief Effectue simultanément un échange entre les deux premiers éléments 
 *        des piles A et B et affiche "ss" sur la sortie standard.
 * 
 * @param stack_a Pointeur vers la pile A.
 * @param stack_b Pointeur vers la pile B.
 * @return 0 si l'opération réussit, -1 si l'une des piles contient 
 * moins de 2 éléments.
 */
int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	return (0);
}
