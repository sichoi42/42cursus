/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:28:17 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 16:31:58 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"

t_camera	camera(t_canvas *canvas, t_in_camera *in_cam)
{
	t_camera	cam;
	double		viewport_height;
	t_vec3		v_up;
	double		theta;
	double		h;

	cam.orig = in_cam->org;
	cam.dir = in_cam->org_vec;
	v_up = get_v_up(cam.dir);
	theta = degree_to_radian(in_cam->fov);
	h = tan(theta / 2.0);
	viewport_height = 2.0 * h;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.w = vflip(cam.dir);
	cam.u = vunit(vcross(v_up, cam.w));
	cam.v = vcross(cam.w, cam.u);
	cam.horizontal = vmult(cam.u, cam.viewport_w);
	cam.vertical = vmult(cam.v, cam.viewport_h);
	cam.left_bottom = vminus(vminus(vminus(cam.orig, \
	vdivide(cam.horizontal, 2)), vdivide(cam.vertical, 2)), cam.w);
	return (cam);
}
