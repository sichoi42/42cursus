/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:48:38 by sichoi            #+#    #+#             */
/*   Updated: 2022/02/24 15:56:56 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	init_lendst;
	size_t	lensrc;
	size_t	i;
	size_t	j;

	init_lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	j = init_lendst;
	while (src[i] && i + init_lendst + 1 < dstsize)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (dstsize < init_lendst)
		return (lensrc + dstsize);
	else
	{
		dst[j] = 0;
		return (lensrc + init_lendst);
	}
}
