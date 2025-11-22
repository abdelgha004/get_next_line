/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:44:25 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/22 10:46:41 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*read_until_newline(int fd, char *saved)
{
	char	*buffer;
	char	*tmp;
	int		byte_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(saved), NULL);
	while (has_newline(saved) == -1)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(buffer), free(saved), NULL);
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		tmp = ft_strjoin(saved, buffer);
		if (!tmp)
			return (free(buffer), free(saved), NULL);
		saved = tmp;
	}
	free(buffer);
	return (saved);
}

static char	*get_line(char *saved)
{
	char	*line;
	int		i;

	if (!saved || !saved[0])
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	line = ft_substr(saved, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*update_saved(char *saved)
{
	char	*new_saved;
	int		i;

	if (!saved || !saved[0])
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
		return (free(saved), NULL);
	new_saved = ft_strdup(saved + (i + 1));
	if (!new_saved)
		return (free(saved), NULL);
	free(saved);
	return (new_saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_until_newline(fd, saved);
	if (!saved)
		return (NULL);
	line = get_line(saved);
	if (!line)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	saved = update_saved(saved);
	return (line);
}
