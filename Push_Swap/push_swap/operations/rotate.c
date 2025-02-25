/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 15:03:02 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 16:12:24 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Effectue une rotation d'une pile chaînée en déplaçant 
 *        son premier élément à la fin de la liste.
 *        Retourne -1 si la pile contient moins de 2 éléments.
 * 
 * @param stack Pointeur vers la pile à faire tourner.
 * @return 0 si l'opération réussit, -1 sinon.
 */
static int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

/**
 * @brief Effectue une rotation de la pile A en déplaçant 
 *        son premier élément à la fin de la liste.
 *        Affiche "ra" sur la sortie standard.
 * 
 * @param stack_a Pointeur vers la pile A.
 * @return 0 si l'opération réussit, -1 si la pile contient moins de 2 éléments.
 */
int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

/**
 * @brief Effectue une rotation de la pile B en déplaçant 
 *        son premier élément à la fin de la liste.
 *        Affiche "rb" sur la sortie standard.
 * 
 * @param stack_b Pointeur vers la pile B.
 * @return 0 si l'opération réussit, -1 si la pile contient moins de 2 éléments.
 */
int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

/**
 * @brief Effectue simultanément une rotation des piles A et B,
 *        en déplaçant leur premier élément à la fin.
 *        Affiche "rr" sur la sortie standard.
 * 
 * @param stack_a Pointeur vers la pile A.
 * @param stack_b Pointeur vers la pile B.
 * @return 0 si l'opération réussit, -1 si l'une des piles 
 * contient moins de 2 éléments.
 */
int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return (0);
}
