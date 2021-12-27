/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsato <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:08:10 by jsato             #+#    #+#             */
/*   Updated: 2021/11/23 16:55:57 by jsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strndup(const char *s1, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen_toc(char const *s1, char c);
char	*ft_strndup(const char *s1, size_t size);
char	*ft_strchr(const char *s, int c);

#endif
