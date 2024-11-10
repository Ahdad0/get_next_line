/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahaded <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:12:04 by abahaded          #+#    #+#             */
/*   Updated: 2024/11/10 15:27:48 by abahaded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_str(char *p);
int		check_newline(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
