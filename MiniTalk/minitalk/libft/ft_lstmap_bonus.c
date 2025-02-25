/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:35:46 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:10:20 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Construit une nouvelle liste en copiant la liste donnée et en appliquant
 * une fonction spécifique à chaque élément.
 *
 * @param lst Premier nœud à partir duquel commencer l'itération.
 * @param f Fonction appliquée sur chaque élément pour modifier le contenu.
 * @param del Fonction pour libérer le contenu des nœuds si besoin.
 * @return Renvoie une nouvelle liste avec les éléments transformés, 
 * ou NULL en cas d'erreur.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*elem;

	if (!f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, elem);
		lst = lst->next;
	}
	return (new);
}
