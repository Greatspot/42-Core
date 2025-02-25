/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:05:19 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/10 17:08:15 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/**
 * @brief Convertit un caractère en binaire et envoie les bits au serveur.
 *
 * @param pid PID du serveur auquel envoyer les signaux.
 * @param c Caractère à convertir et envoyer.
 */

void	convert_binary(int pid, char c)
{
	int	bit;
	int	status;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			status = kill(pid, SIGUSR1);
		else
			status = kill(pid, SIGUSR2);
		if (status == -1)
		{
			ft_putstr_fd("Error:PID not reachable!\n", 1);
			exit(EXIT_FAILURE);
		}
		usleep(500);
		bit++;
	}
}
/**
 * @brief Envoie une chaîne de caractères au serveur en convertissant 
 * chaque caractère en binaire.
 *
 * @param pid PID du serveur auquel envoyer les signaux.
 * @param msg Chaîne de caractères à envoyer.
 */

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		convert_binary(pid, *msg);
		msg++;
	}
	convert_binary(pid, '\n');
}
/**
 * @brief Gère les signaux reçus pour afficher un message de confirmation.
 *
 * @param signum Signal reçu (SIGUSR2 attendu).
 */

void	handle_signal(int signum)
{
	if (signum == SIGUSR2)
		ft_putstr_fd("Message received by the server successfully!\n", 1);
}
/**
 * @brief Point d'entrée principal du programme client_bonus.
 *
 * Configure les signaux, valide les arguments, et envoie le 
 * message au serveur.
 *
 * @param argc Nombre d'arguments passés au programme.
 * @param argv Tableau d'arguments, où argv[1] est le PID et argv[2] 
 * est le message.
 * @return EXIT_SUCCESS si tout se passe bien, EXIT_FAILURE sinon.
 */

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client_bonus <PID> \"message\"\n", 1);
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Error: Invalid PID format!\n", 1);
		return (EXIT_FAILURE);
	}
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: Failed to set signal handler\n", 1);
		return (EXIT_FAILURE);
	}
	send_msg(pid, argv[2]);
	return (EXIT_SUCCESS);
}
