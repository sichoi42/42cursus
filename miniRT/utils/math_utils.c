/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:29:19 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 17:31:35 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	degree_to_radian(double degree)
{
	return (M_PI * degree / 180.0);
}

double	radian_to_degree(double radian)
{
	return (180.0 * radian / M_PI);
}

double	ft_fmod_abs(double x, double mod)
{
	if (x < 0)
		return (x + mod);
	return (x);
}

int	clamp(int x, int min, int max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}
