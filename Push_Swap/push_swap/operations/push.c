/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 15:03:02 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 12:08:09 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Effectue une opération de "push", déplaçant le premier élément
 *        d'une pile source vers une pile destination.
 *        Retourne -1 si la pile source est vide.
 * 
 * @param stack_to Pointeur vers la pile de destination.
 * @param stack_from Pointeur vers la pile source.
 * @return 0 si l'opération réussit, -1 si la pile source est vide.
 */
static int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

/**
 * @brief Effectue un "push" du premier élément de la pile B vers la pile A.
 *        Affiche "pa" sur la sortie standard.
 *        Retourne -1 si la pile B est vide.
 * 
 * @param stack_a Pointeur vers la pile A.
 * @param stack_b Pointeur vers la pile B.
 * @return 0 si l'opération réussit, -1 si la pile B est vide.
 */
int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

/**
 * @brief Effectue un "push" du premier élément de la pile A vers la pile B.
 *        Affiche "pb" sur la sortie standard.
 *        Retourne -1 si la pile A est vide.
 * 
 * @param stack_a Pointeur vers la pile A.
 * @param stack_b Pointeur vers la pile B.
 * @return 0 si l'opération réussit, -1 si la pile A est vide.
 */
int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
