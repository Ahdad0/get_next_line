/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:33:00 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/14 19:02:24 by abahaded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(len + 1);
	if (!p)
		return (free(p), NULL);
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

char	*ft_afterNewline(char *s)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		j = i;
	}
	else
	{
		j = i + 1;
		i++;
	}
	while (s[i])
	{
		i++;
		len++;
	}
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[j])
		new[i++] = s[j++];
	new[i] = '\0';
	return (new);
}

void	ft_untilNewline(char *s)
{
	int		j;

	if (!s)
		return ;
	j = 0;
	while (s[j] && s[j] != '\n')
		j++;
	while (s[j] == '\n' && s[j])
		j++;
	s[j] = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
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

	if (!s)
		return (0);
	j = 0;
	while (s[j])
		j++;
	return (j);
}
