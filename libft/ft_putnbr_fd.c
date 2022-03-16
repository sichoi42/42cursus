/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:01:10 by sichoi            #+#    #+#             */
/*   Updated: 2022/02/24 16:00:07 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	put_print(char tr[], int nb, int fd)
{
	int	i;
	int	j;

	i = nb;
	j = 0;
	while (1)
	{
		if (i < 10)
		{
			tr[j] = i + '0';
			break ;
		}
		tr[j] = i % 10 + '0';
		i /= 10;
		j++;
	}
	while (j >= 0)
	{
		putchar(tr[j], fd);
		j--;
	}
}

void	putnbr(int nb, int fd)
{
	char	tr[12];

	if (nb >= 0)
		put_print(tr, nb, fd);
	else if (nb < 0 && nb != -2147483648)
	{
		putchar('-', fd);
		put_print(tr, -nb, fd);
	}
	else
	{
		nb = -214748364;
		putchar('-', fd);
		put_print(tr, -nb, fd);
		putchar('8', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	putnbr(n, fd);
}
