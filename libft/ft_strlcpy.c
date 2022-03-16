/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:13:08 by sichoi            #+#    #+#             */
/*   Updated: 2022/02/24 15:57:00 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	if (src == 0)
		return (0);
	if (dstsize != 0)
	{
		i = 0;
		while (src[i] && dstsize != 1)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
