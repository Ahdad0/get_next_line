/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:10:49 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/14 19:02:14 by abahaded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_line(int fd, char *store)
{
    char    b[BUFFER_SIZE + 1];
    char    *new_temp;
    int     i;

    if (!store)
        store = ft_strdup("");
    while (ft_strchr(store, '\n') == NULL)
    {
        i = read(fd, b, BUFFER_SIZE);
        if (i == -1)
        {
            free(store);
            return (NULL);
        }
        if (i == 0)
            break;
        b[i] = '\0';
        new_temp = ft_strjoin(store, b);
        free(store);
        if (!new_temp)
            return (NULL);
        store = new_temp;
    }
    return (store);
}

char    *get_next_line(int fd)
{
    char        *line;
    char        *re;
    static char *store;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    store = read_line(fd, store);
    if (!store)
        return (NULL);
    if (!*store)
    {
        free(store);
        store = NULL;
        return (NULL);
    }
    re = ft_untilNewline(store);
    if (!re)
    {
        free(store);
        store = NULL;
        return (NULL);
    }
    line = ft_afterNewline(store);
    free(store);
    store = line;
    return (re);
}