/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 15:09:02 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 13:08:10 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Effectue une rotation inversée d'une pile chaînée en déplaçant 
 *        son dernier élément au début de la liste.
 *        Retourne -1 si la pile contient moins de 2 éléments.
 * 
 * @param stack Pointeur vers la pile à inverser.
 * @return 0 si l'opération réussit, -1 sinon.
 */
static int	reverse(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

/**
 * @brief Effectue une rotation inversée de la pile A en déplaçant 
 *        son dernier élément au début de la liste.
 *        Affiche "rra" sur la sortie standard.
 * 
 * @param stack_a Pointeur vers la pile A.
 * @return 0 si l'opération réussit, -1 si la pile contient moins de 2 éléments.
 */
int	rra(t_list **stack_a)
{
	if (reverse(stack_a) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

/**
 * @brief Effectue une rotation inversée de la pile B en déplaçant 
 *        son dernier élément au début de la liste.
 *        Affiche "rrb" sur la sortie standard.
 * 
 * @param stack_b Pointeur vers la pile B.
 * @return 0 si l'opération réussit, -1 si la pile contient moins de 2 éléments.
 */
int	rrb(t_list **stack_b)
{
	if (reverse(stack_b) == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

/**
 * @brief Effectue simultanément une rotation inversée des piles A et B,
 *        en déplaçant leur dernier élément au début.
 *        Affiche "rrr" sur la sortie standard.
 * 
 * @param stack_a Pointeur vers la pile A.
 * @param stack_b Pointeur vers la pile B.
 * @return 0 si l'opération réussit, -1 si l'une des piles 
 * contient moins de 2 éléments.
 */
int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}
