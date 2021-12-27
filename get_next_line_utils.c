/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsato <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:08:00 by jsato             #+#    #+#             */
/*   Updated: 2021/11/23 16:54:33 by jsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_toc(char const *s1, char c)
{
	size_t	counter;

	counter = 0;
	while (*s1 && *s1++ != c)
		counter++;
	return (counter);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;
	size_t			counter;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (dst == (void *)0 && src == (void *)0)
		return ((void *)0);
	if (dst_p > src_p && ((src_p + len) > dst_p))
	{
		while (len)
		{
			dst_p[len - 1] = src_p[len - 1];
			len--;
		}
		return (dst);
	}
	counter = 0;
	while (len--)
	{
		dst_p[counter] = src_p[counter];
		counter++;
	}
	return (dst);
}

char	*ft_strndup(const char *s1, size_t size)
{
	size_t	len_str;
	char	*p;
	char	*start;

	len_str = ft_strlen_toc(s1, 0) + 1;
	if (len_str > size)
		len_str = size;
	p = (char *)malloc(len_str);
	if (!p)
		return ((void *)0);
	start = p;
	while (*s1 && --size)
	{
		*p = *s1;
		p++;
		s1++;
	}
	*p = 0;
	return (start);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answ;
	char	*loc;

	if (!s2 || !s1)
		return ((void *)0);
	loc = (char *)malloc(ft_strlen_toc(s1, 0) + ft_strlen_toc(s2, 0) + 1);
	if (loc == (void *)0)
		return ((void *)0);
	answ = loc;
	while (*s1)
	{
		*loc = *s1;
		s1++;
		loc++;
	}
	while (*s2)
	{
		*loc = *s2;
		s2++;
		loc++;
	}
	*loc = *s2;
	return (answ);
}

char	*ft_strchr(const char *s, int c)
{
	char	character;

	character = (char)c;
	while (*s)
	{
		if (*s == character)
			return ((char *)s);
		s++;
	}
	if (*s == character)
		return ((char *)s);
	return ((void *)0);
}
