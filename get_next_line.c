/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:03:53 by aakourya          #+#    #+#             */
/*   Updated: 2025/11/17 16:54:29 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd){
    int buf_size = 5;
    char buff[buf_size + 1];
    static char* tmp;
    char *keep_tmp;
    int finish = 1;
    while (finish)
    {
        read(fd, buff, buf_size);
        buff[buf_size + 1] = '\0';
        ft_strdup(buff);
    }
}
