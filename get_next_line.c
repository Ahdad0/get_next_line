/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:10:49 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/14 12:11:12 by abahaded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		b[BUFFER_SIZE + 1];
	static char	*ori;
	char 		*temp;
	int			i;

	if (BUFFER_SIZE <= 0 || fd <= -1)
		return (NULL);
	ori = NULL;
	while (ft_strchr(ori, '\n') == NULL)
	{
		i = read(fd, b, BUFFER_SIZE);
		if (i == -1)
		{
			return (NULL);
		}
		b[i] = '\0';
		temp = ft_strjoin(ori, b);
		ori = temp;
	}
	ori = ft_afterNewline(temp);
	ft_untilNewline(temp);
	return (temp);
}
