/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:33:00 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/10 22:38:00 by abahaded         ###   ########.fr       */
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
		i++;
	}
	return (0);
}
static char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (dest[i])
		i++;
	while (src[o])
		dest[i++] = src[o++];
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strncat(char *dest, char const *src, size_t nb)
{
	int		i;
	size_t	o;

	i = 0;
	o = 0;
	while (dest[i])
		i++;
	while (src[o] && o < nb)
		dest[i++] = src[o++];
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	max;
	size_t	sub;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	max = len_dest + len_src + 1;
	sub = size - len_dest - 1;
	if (size < len_dest)
		return (size + len_src);
	else if (size >= max)
		ft_strcat(dest, src);
	else if (len_dest < size && size <= max)
		ft_strncat(dest, src, sub);
	return (len_dest + len_src);
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

size_t	ft_strlen(const char *s)
{
	unsigned int	j;

	j = 0;
	while (s[j])
		j++;
	return (j);
}

char	*ft_rts(char *s)
{
	int		i = 0;
	int 	len = 0;
	char	*p;
	int		o = 0;

	while (s[i] != '\n')
		i++;
	len = ft_strlen(s + i);
	p = malloc(len + 1);
	if (!p)
	{
		free(p);
		return (NULL);
	}
	while (s[i])
		p[o++] = s[i++];
	p[o] = '\0';
	return (p);
}
