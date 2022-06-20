/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_select.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:42:46 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 18:14:30 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

void	hit_color_select(t_hit_record *rec, t_obj *obj)
{
	if (rec->texture == CHECKERBOARD)
		checkerboard(rec);
	else if (rec->texture == BUMP_MAP)
		bump_mapping(rec, obj);
	else
		rec->albedo = obj->albedo;
}
