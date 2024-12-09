/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:31:27 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 17:56:11 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Supprime le node spécifié en utilisant la fonction del
 * pour libérer son contenu, puis libère le nœud lui-même.
 *
 * @param lst Node à supprimer.
 * @param del Fonction pour libérer le contenu du node.
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
