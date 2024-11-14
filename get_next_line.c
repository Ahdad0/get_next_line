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
	char	b[BUFFER_SIZE + 1];
	char	*new_temp;
	char	*temp;
	int		i;

	temp = store;
	store = NULL;
	while (ft_strchr(temp, '\n') == NULL)
	{
		i = read(fd, b, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			return (NULL);
		}
		if (i == 0)
			break;
		b[i] = '\0';
		new_temp = ft_strjoin(temp, b);
		free(temp);
		temp = new_temp;
	}
	return (temp);
}
char	*get_next_line(int fd)
{
	char		*line;
	char		*re;
	static char	*store;

	if (BUFFER_SIZE <= 0 || fd <= -1)
		return (NULL);
	line = read_line(fd, store);
	re = ft_untilNewline(line);
	store = ft_afterNewline(line);
	return (re);
}
