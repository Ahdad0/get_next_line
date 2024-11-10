/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:12:04 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/10 13:01:29 by abahaded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>

void	get_next_line(int fd);
char	*ft_argnew(char *p, int index);
int		check_newline(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
