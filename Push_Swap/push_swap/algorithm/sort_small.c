/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 20:27:38 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 10:17:50 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Effectue une rotation suivie d'un échange, puis une rotation inverse.
 *        Spécifique au cas où la pile est sous la forme 1-3-2.
 *
 * @param stack_a Pointeur vers la pile principale.
 */
static void	sort_132(t_list **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

/**
 * @brief Trie la pile lorsque la configuration est 2-3-1.
 *        Vérifie si le deuxième élément est le minimum et échange si nécessaire.
 *
 * @param stack_a Pointeur vers la pile principale.
 * @param head Pointeur vers le sommet de la pile.
 * @param min Valeur minimale présente dans la pile.
 */
static void	sort_231(t_list **stack_a, t_list *head, int min)
{
	if (head->next->index == min)
		sa(stack_a);
	else
		rra(stack_a);
}

/**
 * @brief Trie la pile lorsque la configuration est 3-1-2.
 * Effectue une rotation si nécessaire, sinon échange puis rotation inverse.
 *
 * @param stack_a Pointeur vers la pile principale.
 * @param head Pointeur vers le sommet de la pile.
 * @param min Valeur minimale présente dans la pile.
 */
static void	sort_312(t_list **stack_a, t_list *head, int min)
{
	if (head->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

/**
 * @brief Trie une pile de trois éléments en appliquant les algorithmes de tri 
 *  spécifiques aux différentes configurations possibles. Vérifie d'abord 
 * si la pile est déjà triée, puis applique sort_132, sort_231 ou sort_312.
 *
 * @param stack_a Pointeur vers la pile principale.
 */
void	sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a) == 1)
		return ;
	if (head->index == min && head->next->index != next_min)
		sort_132(stack_a);
	else if (head->index == next_min)
		sort_231(stack_a, head, min);
	else
		sort_312(stack_a, head, min);
}
