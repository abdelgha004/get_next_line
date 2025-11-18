/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:03:53 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/18 22:19:16 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			buffer_size;
	char		buffer[buffer_size + 1];
	static char	*buffered_text;
	char		*joined;
	char		*line;
	int			index;
	int			reading;
	int			bytes_read;

	buffer_size = 42;
	index = 0;
	reading = 1;
	bytes_read = read(fd, buffer, buffer_size - 1);
	if (bytes_read == -1)
		return (NULL);
	buffer[bytes_read] = '\0';
	buffered_text = ft_strdup(buffer);
	if (!buffered_text)
		return (NULL);
	while (reading)
	{
		bytes_read = read(fd, buffer, buffer_size - 1);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		joined = ft_strjoin(buffered_text, buffer);
		if (!joined)
			return (NULL);
		free(buffered_text);
		while (joined[index])
		{
			if (joined[index] == '\n' || !joined[index])
			{
				reading = 0;
				break ;
			}
			index++;
		}
		buffered_text = ft_substr(joined, 0, index);
		if (!buffered_text)
			return (NULL);
		free(joined);
	}
	line = ft_strdup(buffered_text);
	if (!line)
		return (NULL);
	return (line);
}
