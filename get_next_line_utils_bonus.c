#include "get_next_line_bonus.h"

char	*ft_strjoinn(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len = ft_strlenn(s1) + ft_strlenn(s2);
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

char	*ft_untilnewlinee(char *s)
{
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*ft_afternewlinee(char *s)
{
	char	*new;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (NULL);
	i++;
	new = malloc(ft_strlenn(s) - i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}

char	*ft_strchrr(const char *s, int c)
{
	size_t	i;

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

size_t	ft_strlenn(const char *s)
{
	size_t	j;

	if (!s)
		return (0);
	j = 0;
	while (s[j])
		j++;
	return (j);
}
