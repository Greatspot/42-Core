/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 08:02:13 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 11:08:17 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Ajoute un nouvel élément au début d'une liste chaînée.
 * 
 * @param stack Pointeur vers le début de la liste.
 * @param new Pointeur vers le nouvel élément à ajouter.
 */
void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}
