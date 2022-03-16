/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:02:53 by sichoi            #+#    #+#             */
/*   Updated: 2022/02/24 16:08:16 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *tgt, size_t len)
{
	size_t	n;

	if (*tgt == 0)
		return ((char *)dst);
	n = ft_strlen(tgt);
	while (*dst && len >= n)
	{
		if (ft_strncmp(dst, tgt, n) == 0)
			return ((char *)dst);
		dst++;
		len--;
	}
	return (0);
}
