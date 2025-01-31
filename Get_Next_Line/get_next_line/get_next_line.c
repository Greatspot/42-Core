/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:30:05 by rcunha-l          #+#    #+#             */
/*   Updated: 2024/11/09 18:30:05 by rcunha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/**
 * @brief Fusionne deux chaînes et libère la mémoire de la première.
 *
 * @param s1 Première chaîne à fusionner.
 * @param s2 Deuxième chaîne.
 * @return Chaîne fusionnée.
 */
char	*ft_join_free(char *s1, char *s2)
{
	char	*temp_buffer;

	temp_buffer = ft_strjoin(s1, s2);
	free(s1);
	return (temp_buffer);
}

/**
 * @brief Extrait une ligne d'un buffer donné.
 *
 * @param buffer Buffer source.
 * @return Ligne extraite ou NULL en cas d'erreur.
 */
char	*ft_fill_line(const char *buffer)
{
	char	*line;
	size_t	line_len;
	size_t	i;

	line_len = 0;
	while (buffer[line_len] && buffer[line_len] != '\n')
		line_len++;
	if (buffer[line_len] == '\n')
		line_len++;
	line = (char *)malloc(line_len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < line_len)
		line[i] = buffer[i];
	line[i] = '\0';
	return (line);
}

/**
 * @brief Met à jour le buffer après avoir lu une ligne.
 *
 * @param buffer Buffer source.
 * @param line Ligne extraite.
 * @return Nouveau buffer mis à jour.
 */
char	*ft_update_buffer(char *buffer, const char *line)
{
	size_t	buffer_len;
	size_t	line_len;
	ssize_t	i;
	char	*new_buffer;

	buffer_len = ft_strlen(buffer);
	line_len = ft_strlen(line);
	if (buffer_len == line_len)
		return (free(buffer), NULL);
	new_buffer = (char *)malloc(buffer_len - line_len + 1);
	if (!new_buffer)
		return (free(buffer), NULL);
	i = -1;
	while (buffer[line_len + ++i])
		new_buffer[i] = buffer[line_len + i];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

/**
 * @brief Remplit un buffer en lisant depuis un fichier.
 *
 * @param fd Descripteur de fichier.
 * @param buffer Buffer existant.
 * @return Buffer rempli ou NULL.
 */
char	*ft_fill_buffer(int fd, char *buffer)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(temp_buffer), NULL);
		temp_buffer[bytes_read] = '\0';
		buffer = ft_join_free(buffer, temp_buffer);
		if (!buffer)
			return (free(temp_buffer), NULL);
		if (ft_strchr(temp_buffer, '\n'))
			break ;
	}
	return (free(temp_buffer), buffer);
}

/**
 * @brief Lit une ligne depuis un fichier.
 *
 * @param fd Descripteur de fichier.
 * @return Ligne extraite ou NULL si fin de fichier.
 */
char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer = ft_fill_buffer(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = ft_fill_line(static_buffer);
	if (!line || !(line[0]))
	{
		free(static_buffer);
		static_buffer = NULL;
		return (free(line), NULL);
	}
	static_buffer = ft_update_buffer(static_buffer, line);
	return (line);
}
