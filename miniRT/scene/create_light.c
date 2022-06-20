/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:26:33 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 16:53:44 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "parsing.h"
#include "utils.h"
#include "init.h"
#include <stdlib.h>

t_light	*point_light(t_in_light *in_light)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		exit(1);
	light->orig = in_light->org;
	light->light_color = in_light->rgb;
	light->bright_ratio = in_light->ratio;
	return (light);
}
