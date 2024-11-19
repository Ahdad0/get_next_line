/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:21:27 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/19 20:31:51 by abahaded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*p;
	int		i;

	len = ft_strlen(s);
	i = 0;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	*read_line(int fd, char *store)
{
	char	*b;
	char	*new_temp;
	int		i;

	if (!store)
		store = ft_strdup("");
	b = malloc(BUFFER_SIZE + 1);
	if (!b)
		return (free(store), NULL);
	while (ft_strchr(store, '\n') == NULL)
	{
		i = read(fd, b, BUFFER_SIZE);
		if (i == -1)
			return (free(b), free(store), NULL);
		if (i == 0)
			break ;
		b[i] = '\0';
		new_temp = ft_strjoin(store, b);
		free(store);
		if (!new_temp)
			return (free(b), NULL);
		store = new_temp;
	}
	free(b);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*re;
	static char	*store[1024];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	store[fd] = read_line(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	if (!*store[fd])
		return (free(store[fd]), store[fd] = NULL, NULL);
	re = ft_untilnewline(store[fd]);
	if (!re)
		return (free(store[fd]), store[fd] = NULL, NULL);
	line = ft_afternewline(store[fd]);
	free(store[fd]);
	store[fd] = line;
	return (re);
}
