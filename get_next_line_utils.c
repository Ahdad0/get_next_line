/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:33:00 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/10 15:23:06 by abahaded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	len_of_src;
	size_t			i;

	i = 0;
	len_of_src = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && size - 1 > i)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_of_src);
}

char	*ft_str(char *p)
{
	int i = 0;

	while (p[i] != '\n')
		i++;

	char *new = malloc(i + 1);
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (p[i] != '\n')
	{
		new[i] = p[i];
		i++;
	}
	return (new);
}
