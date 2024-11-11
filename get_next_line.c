/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:10:49 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/11 18:05:21 by abahaded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		b[BUFFER_SIZE];
	static char	*p;
	char 		*s;
	char		temp[1024];
	int			i;

	temp[0] = '\0';
	while (check_newline(temp) == 0)
	{
		i = read(fd, b, BUFFER_SIZE);
		if (i == -1 || i == 0)
			return (NULL);
		if (temp[0] == '\0')
			ft_strlcpy(temp, b, sizeof(temp));
		else
			ft_strlcat(temp, b, sizeof(temp));
	}
	s = ft_str(temp);
	p = ft_rts(temp);
	return (s);
}
