/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 08:10:24 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 10:02:28 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

	/*
	Creates a new node for a linked list with the given integer value.
	Allocates memory for the new node using malloc and sets the initial
	values for the node's value, index, and next pointer.
	-1 to represent an unset or invalid index value.
	Returns a pointer to the newly created node.
	*/

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}
