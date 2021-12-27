/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsato <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:37:34 by jsato             #+#    #+#             */
/*   Updated: 2021/11/23 16:46:24 by jsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	turbo_mega_frisher_v2(char *trash1, char *trash2)
{
	free(trash1);
	free(trash2);
}

void	ft_memset(char *dest, char c, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		dest[i] = c;
}

char	*split_by_nl(char *buff)
{
	size_t	len;
	char	*ret;

	if (ft_strlen_toc(buff, 0) == ft_strlen_toc(buff, '\n'))
	{
		ret = ft_strndup(buff, BUFFER_SIZE + 1);
		ft_memset(buff, 0, BUFFER_SIZE + 1);
	}
	else
	{
		len = ft_strlen_toc(buff, '\n') + 2;
		ret = ft_strndup(buff, len);
		ft_memmove(buff, &buff[len - 1], ft_strlen_toc(buff, 0) - (len - 1));
		ft_memset(&buff[ft_strlen_toc(buff, 0) - (len - 1)], 0, len - 1);
	}
	return (ret);
}

void	extension_function(char **tmp, char *buffer)
{
	tmp[0] = tmp[2];
	tmp[1] = split_by_nl(buffer);
	tmp[2] = ft_strjoin(tmp[0], tmp[1]);
	turbo_mega_frisher_v2(tmp[0], tmp[1]);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*tmp[3];
	ssize_t			len;

	len = BUFFER_SIZE;
	tmp[2] = NULL;
	while (len == BUFFER_SIZE)
	{
		if (!*buffer)
			len = read(fd, buffer, BUFFER_SIZE);
		if (len > 0)
		{
			if (!tmp[2])
				tmp[2] = split_by_nl(buffer);
			else
				extension_function(tmp, buffer);
			if (len != BUFFER_SIZE || ft_strchr(tmp[2], '\n'))
				break ;
		}		
	}
	return (tmp[2]);
}
