/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:03:53 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/20 10:37:04 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int check_nl(char *str)
{
    int i;
    i = 0;
    if (!str)
        return (-1);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

static char *read_and_join(int fd, char *stash)
{
    char *buffer;
    int bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (check_nl(stash) == -1)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (stash);
		}
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (!stash)
            return (NULL);
    }
    free(buffer);
    return (stash);
}

static char *extract_line(char *stash)
{
    int i = 0;
    char *line;

    if (!stash || !stash[0])
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = ft_substr(stash, 0, i);
    return (line);
}

static char *clean_stash(char *stash)
{
    int i = 0;
    char *new_stash;

    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
        return (free(stash), NULL);
    new_stash = ft_strdup(stash + i + 1);
    free(stash);
    return (new_stash);
}

char *get_next_line(int fd)
{
    static char *tmp[1024];
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    tmp[fd] = read_and_join(fd, tmp[fd]);
    if (!tmp[fd])
        return (NULL);

    line = extract_line(tmp[fd]);
    tmp[fd] = clean_stash(tmp[fd]);
    return (line);
}
