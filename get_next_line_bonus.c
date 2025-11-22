/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:03:53 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/22 10:50:52 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	has_newline(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
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
	static char	*saved[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	saved[fd] = read_until_newline(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = get_line(saved[fd]);
	if (!line)
	{
		free(saved[fd]);
		saved[fd] = NULL;
		return (NULL);
	}
	saved[fd] = update_saved(saved[fd]);
	return (line);
}
