/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:05:39 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/09 19:10:26 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/**
 * @brief Convertit un caractère en binaire et envoie ses bits au serveur.
 *
 * Chaque bit est envoyé via des signaux SIGUSR1 ou SIGUSR2, en fonction 
 * de la valeur binaire du caractère.
 *
 * @param pid PID du serveur auquel envoyer les signaux.
 * @param c Caractère à convertir et envoyer.
 */

void	convert_binary(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}
/**
 * @brief Envoie une chaîne de caractères au serveur en binaire.
 *
 * Parcourt chaque caractère de la chaîne, le convertit en binaire 
 * et l'envoie via des signaux.
 * Termine le message avec un caractère '\n'.
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
 * @brief Point d'entrée principal du client.
 *
 * Valide les arguments du programme, vérifie le PID, et envoie 
 * un message au serveur.
 * Affiche des messages d'erreur si les arguments sont invalides 
 * ou si le serveur n'est pas accessible.
 *
 * @param argc Nombre d'arguments passés au programme.
 * @param argv Tableau d'arguments, où argv[1] est le PID et argv[2] 
 * est le message.
 * @return Retourne 0 en cas de succès, ou affiche un message d'erreur 
 * en cas d'échec.
 */

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (write(1, "Error: Wrong format!\n", 21));
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (write(1, "Error: Invalid PID!\n", 20));
	if (kill(pid, 0) != 0)
		return (write(1, "Error: PID not reachable!\n", 26));
	send_msg(pid, argv[2]);
	write(1, "Message sent!\n", 14);
	return (0);
}
