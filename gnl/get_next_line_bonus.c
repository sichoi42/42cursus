/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:48:52 by sichoi            #+#    #+#             */
/*   Updated: 2021/06/24 22:04:22 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*bak[256];
	int			n;

	*line = 0;
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while (1)
	{
		init_buf(buf);
		if (f_nl(bak[fd], 0) >= 0)
		{
			return (!(*line = join(*line, bak[fd], f_nl(bak[fd], 1) + 1))
			|| !(bak[fd] = bak_after_nl(bak[fd])) ? -1 : 1);
		}
		if ((n = read(fd, buf, BUFFER_SIZE)) <= 0)
		{
			if (!(*line = join(*line, bak[fd], f_nl(bak[fd], 1) + 1)) || n < 0)
				break ;
			return (!(bak[fd] = ft_free(bak[fd])) && (*line)[0] ? 0 : n);
		}
		if (!(bak[fd] = join(bak[fd], buf, f_nl(bak[fd], 1) + ft_len(buf) + 1)))
			break ;
	}
	return (!(bak[fd] = ft_free(bak[fd])) ? -1 : 0);
}

int		f_nl(char *s, int is_len)
{
	int i;

	if (s == 0 && is_len == 1)
		return (0);
	if (s == 0 && is_len == 0)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	if (is_len == 1)
		return (i);
	return (-1);
}

char	*join(char *dst, const char *src, int size)
{
	char	*result;
	int		i;
	int		len_dst;

	i = 0;
	if (src == 0)
	{
		result = ft_strdup("");
		return (result);
	}
	if ((result = malloc(sizeof(char) * size)) == 0)
		return (0);
	len_dst = ft_len(dst);
	if (dst)
	{
		i = ft_strlcpy(result, dst, len_dst + 1);
		free(dst);
	}
	ft_strlcpy(result + i, src, size - len_dst);
	return (result);
}

char	*bak_after_nl(char *bak)
{
	char	*result;
	int		i;

	i = 0;
	result = bak;
	while (bak[i])
	{
		if (bak[i] == '\n')
		{
			result = 0;
			if (i == ft_len(bak) - 1)
			{
				result = ft_strdup("");
				free(bak);
				return (result);
			}
			result = join(result, bak + i + 1, ft_len(bak + i + 1) + 1);
			free(bak);
			return (result);
		}
		i++;
	}
	return (result);
}
