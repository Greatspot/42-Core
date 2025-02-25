/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 15:03:02 by rcunha-l          #+#    #+#             */
/*   Updated: 2025-02-05 17:16:12 by rcunha-l         ###   ########.lu       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/**
 * @brief Affiche un message d'erreur et termine le programme.
 * 
 * @param msg Message d'erreur (non utilisé dans cette implémentation).
 */
void	error_message(char *msg)
{
	(void)msg;
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/**
 * @brief Libère la mémoire allouée pour un tableau de chaînes de caractères.
 * 
 * @param str Tableau de chaînes de caractères à libérer.
 */
void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

/**
 * @brief Libère la mémoire allouée pour une pile représentée 
 * par une liste chaînée.
 * Chaque nœud est libéré individuellement avant de libérer 
 * la liste elle-même.
 * 
 * @param stack Pointeur vers la pile à libérer.
 */
void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
