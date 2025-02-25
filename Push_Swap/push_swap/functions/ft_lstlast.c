/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 08:02:19 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 10:09:10 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Parcourt une liste chaînée et retourne un pointeur 
 * vers le dernier nœud.
 *        Suit les pointeurs `next` jusqu'à atteindre le dernier 
 * élément de la liste.
 * 
 * @param head Pointeur vers le premier élément de la liste.
 * @return Pointeur vers le dernier élément de la liste chaînée.
 */
t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}
