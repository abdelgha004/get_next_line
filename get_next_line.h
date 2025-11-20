/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:27:11 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/20 09:47:26 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdio.h> //to remove
#include <stdlib.h>
#include <unistd.h> //to remove

char *get_next_line(int fd);

char *ft_strdup(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char *s1, char *s2);

#endif