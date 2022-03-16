/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:49:03 by sichoi            #+#    #+#             */
/*   Updated: 2021/06/24 22:00:37 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_buf(char *buf)
{
	int i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
}

char	*ft_free(char *s)
{
	if (s)
		free(s);
	return (0);
}

int		ft_len(const char *s)
{
	int i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int i;

	i = 0;
	if (src == 0)
		return (0);
	if (dstsize != 0)
	{
		while (src[i] && dstsize != 1)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = 0;
	}
	return (ft_len(src));
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	if ((p = malloc(ft_len(s) + 1)) == 0)
		return (0);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
