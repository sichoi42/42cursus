/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:36:24 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 17:36:40 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parsing.h"

// 단위 벡터
t_vec3	vunit(t_vec3 vec)
{
	double	len;

	len = vlength(vec);
	if (len == 0)
	{
		printf("%lf %lf %lf\n", vec.x, vec.y, vec.z);
		print_error("Devider is 0");
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}

// 두 벡터의 원소를 비교하여 작은 값들만 반환
t_vec3	vmin(t_vec3 vec, t_vec3 vec2)
{
	if (vec.x > vec2.x)
		vec.x = vec2.x;
	if (vec.y > vec2.y)
		vec.y = vec2.y;
	if (vec.z > vec2.z)
		vec.z = vec2.z;
	return (vec);
}

t_bool	is_same_vec(t_vec3 vec, t_vec3 vec2)
{
	if (vec.x == vec2.x && vec.y == vec2.y && vec.z == vec2.z)
		return (TRUE);
	return (FALSE);
}

t_vec3	get_v_up(t_vec3 vec)
{
	t_vec3	v_up;

	if (is_same_vec(vec, vec3(0, 1, 0)))
		v_up = vec3(0, 0, 1);
	else if (is_same_vec(vec, vec3(0, -1, 0)))
		v_up = vec3(0, 0, -1);
	else
		v_up = vec3(0, 1, 0);
	return (v_up);
}

t_vec3	vflip(t_vec3 vec)
{
	t_vec3	flip;

	flip.x = -vec.x;
	flip.y = -vec.y;
	flip.z = -vec.z;
	return (flip);
}
