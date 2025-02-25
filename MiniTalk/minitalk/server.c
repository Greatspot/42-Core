/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:09 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/09 19:01:02 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/**
 * @brief Gère les signaux SIGUSR1 et SIGUSR2 pour reconstruire un caractère.
 *
 * Chaque signal reçu est utilisé pour reconstruire un caractère, bit par bit.
 * Une fois que 8 bits sont reçus, le caractère complet est traité.
 * Si le caractère est '\n', le serveur envoie une confirmation au client.
 *
 * @param sig Signal reçu (SIGUSR1 ou SIGUSR2).
 * @param info Structure contenant des informations sur le client.
 * @param context Contexte non utilisé dans cette fonction.
 */
void	handle_bit(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;

	(void)context;
	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\n')
		{
			ft_putstr_fd("\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}
/**
 * @brief Point d'entrée principal du serveur.
 *
 * Configure les gestionnaires de signaux pour traiter les messages envoyés
 * par les clients. Affiche le PID du serveur pour permettre
 * aux clients de se connecter.
 * Le serveur reste en écoute indéfinie des signaux.
 *
 * @return Toujours 0 (succès).
 */

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_bit;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
