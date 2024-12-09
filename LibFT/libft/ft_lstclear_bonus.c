/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:31:12 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:55:38 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Vide une liste en supprimant son contenu, en la définissant à NULL
 * et en libérant la mémoire associée.
 *
 * @param lst La liste à vider.
 * @param del Fonction utilisée pour supprimer le contenu des éléments.
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		current = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(current);
	}
}
