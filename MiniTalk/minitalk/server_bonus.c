/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:04:42 by rcunha-l          #+#    #+#             */
/*   Updated: 2025/01/10 16:31:20 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"
/**
 * @brief Ajoute un octet à une chaîne de caractères dynamique.
 *
 * Cette fonction alloue un nouvel espace mémoire pour concaténer un octet
 * (sous forme de caractère) à la chaîne existante et libère l'ancienne mémoire.
 *
 * @param g_str Pointeur vers la chaîne à laquelle ajouter l'octet.
 * @param bytevalue Valeur de l'octet à ajouter.
 */

void	append_byte(char **g_str, int bytevalue)
{
	char	*temp;
	char	*temp_str;

	temp = (char *)malloc(sizeof(char) * 2);
	if (!temp)
		return ;
	temp[0] = (char)bytevalue;
	temp[1] = '\0';
	if (*g_str)
		temp_str = ft_strjoin(*g_str, temp);
	else
		temp_str = ft_strdup(temp);
	if (*g_str)
		free(*g_str);
	*g_str = temp_str;
	free(temp);
}
/**
 * @brief Affiche le message reçu et libère la mémoire associée.
 *
 * Affiche la chaîne stockée dans `g_str` avec un préfixe "Message: ".
 * Si aucun message n'a été reçu, affiche "No message received."
 * Envoie un signal SIGUSR2 au client pour confirmer la réception.
 *
 * @param g_str Pointeur vers la chaîne contenant le message reçu.
 * @param info Structure contenant des informations sur le client.
 */

void	print_and_clear(char **g_str, siginfo_t *info)
{
	if (*g_str)
	{
		ft_putstr_fd("\nMessage: ", 1);
		ft_putstr_fd(*g_str, 1);
		free(*g_str);
		*g_str = NULL;
	}
	else
	{
		ft_putstr_fd("\nNo message received.\n", 1);
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_putstr_fd("Failed to send confirmation\n", 1);
}
/**
 * @brief Traite un octet reçu et construit progressivement le message complet.
 *
 * Ajoute chaque octet reçu à une chaîne dynamique et déclenche l'affichage
 * lorsque le caractère '\n' est détecté.
 *
 * @param bytevalue Valeur de l'octet à traiter.
 * @param info Structure contenant des informations sur le client.
 */

void	process_byte(int bytevalue, siginfo_t *info)
{
	static char	*g_str = NULL;

	append_byte(&g_str, bytevalue);
	if (bytevalue == '\n')
		print_and_clear(&g_str, info);
}
/**
 * @brief Gère les signaux SIGUSR1 et SIGUSR2 pour décoder un octet.
 *
 * Reconstruit un octet bit par bit en fonction des signaux reçus
 * et transmet l'octet complet à `process_byte` une fois que 8 bits sont reçus.
 *
 * @param signum Signal reçu (SIGUSR1 ou SIGUSR2).
 * @param info Structure contenant des informations sur le client.
 * @param context Contexte non utilisé dans cette fonction.
 */

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	byte = 0;

	(void)context;
	if (signum == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		process_byte(byte, info);
		bit = 0;
		byte = 0;
	}
}
/**
 * @brief Point d'entrée principal du serveur.
 *
 * Configure les gestionnaires de signaux pour traiter les messages
 * envoyés par les clients et affiche son PID pour que les clients puissent
 * se connecter. Le serveur attend indéfiniment des messages.
 *
 * @return Toujours 0 (succès).
 */

int	main(void)
{
	struct sigaction	srv_signal;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	srv_signal.sa_sigaction = handle_signal;
	srv_signal.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &srv_signal, NULL) == -1)
		ft_putstr_fd("Failed to set SIGUSR1 behavior\n", 1);
	if (sigaction(SIGUSR2, &srv_signal, NULL) == -1)
		ft_putstr_fd("Failed to set SIGUSR2 behavior\n", 1);
	while (1)
		pause();
	return (0);
}
