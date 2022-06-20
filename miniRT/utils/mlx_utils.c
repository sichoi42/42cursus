/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:08:04 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:33:11 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <stdlib.h>

int	key_exit(int param)
{
	exit(param);
	return (0);
}

int	key_esc(int key)
{
	if (key == ESC)
		key_exit(0);
	return (0);
}
