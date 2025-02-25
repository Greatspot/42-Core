/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:35:55 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/01 18:10:55 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Initialise une nouvelle liste chaînée et assigne une valeur
 * donnée au contenu du premier nœud.
 *
 * @param content Valeur à enregistrer dans le premier nœud.
 * @return Le nœud de la liste nouvellement créée.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*fresh_elem;

	fresh_elem = (t_list *)malloc(sizeof(t_list));
	if (!fresh_elem)
		return (NULL);
	fresh_elem->content = content;
	fresh_elem->next = NULL;
	return (fresh_elem);
}
