/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 08:02:06 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 10:08:09 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Ajoute un nouvel élément à la fin d'une liste chaînée.
 *        Si la liste est vide, l'élément devient le premier élément.
 * 
 * @param stack Pointeur vers le début de la liste.
 * @param new Pointeur vers le nouvel élément à ajouter.
 */
void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*node;

	if (*stack)
	{
		node = ft_lstlast(*stack);
		node->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}
