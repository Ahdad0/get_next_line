/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:33:00 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/14 12:11:14 by abahaded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = ((char *)s1)[i];
		i++;
	}
	while (s2[j])
		p[i++] = ((char *)s2)[j++];
	p[i] = '\0';
	return (p);
}

char	*ft_afterNewline(const char *s)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i] && s[i] != '\n')
		i++;
	j = i;
	while (s[i])
	{
		i++;
		len++;
	}
	new = malloc(len + 1);
	if (!new)
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (s[j])
		new[i++] = s[j++];
	new[i] = '\0';
	return (new);
}

void	ft_untilNewline(char *s)
{
	int		j;

	j = 0;
	while (s[j] && s[j] != '\n')
	{
		if (s[j] == '\n')
			s[j + 1] = '\0';
		j++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j])
		j++;
	return (j);
}
