/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 15:03:02 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 17:19:49 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Calcule la distance entre un index donné et le début d'une pile
 *        représentée sous forme de liste chaînée.
 *
 * @param stack Pointeur vers la pile (liste chaînée).
 * @param index L'index à localiser dans la pile.
 * @return La distance entre le début de la pile et l'index donné.
 */
int	index_distance_head(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

/**
 * @brief Trouve et retourne la valeur minimale d'une pile, à l'exclusion
 *        d'une valeur spécifiée.
 *
 * @param stack Pointeur vers la pile (liste chaînée).
 * @param val La valeur à exclure de la recherche.
 * @return La valeur minimale trouvée dans la pile.
 */
int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}
/**
 * @brief Attribue un index unique à chaque élément de la pile en fonction
 *        de leurs valeurs, en s'assurant que la pile est parcourue de manière
 *        efficace et conforme aux normes.
 *
 * @param stack Pointeur vers la pile (liste chaînée).
 */

void	index_stack(t_list **stack)
{
	t_list	*current;
	t_list	*temp;
	int		index;

	index = 0;
	while (index < ft_lstsize(*stack))
	{
		current = NULL;
		temp = *stack;
		while (temp)
		{
			if (temp->index == -1 && (!current || temp->value < current->value))
				current = temp;
			temp = temp->next;
		}
		if (current)
			current->index = index++;
	}
}

/**
 * @brief Vérifie si une pile est triée dans l'ordre croissant. 
 *        Retourne 1 si elle est triée, sinon 0.
 *
 * @param stack Pointeur vers la pile (liste chaînée).
 * @return 1 si la pile est triée, sinon 0.
 */
int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
