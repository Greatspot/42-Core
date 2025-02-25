/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:35:32 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:08:57 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applique une fonction donnée à chaque nœud, depuis le nœud spécifié
 * jusqu'à la fin de la liste.
 *
 * @param lst Nœud de départ pour l'itération.
 * @param f Fonction à appliquer sur chaque nœud.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
