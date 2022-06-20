/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:13:33 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 16:54:20 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "parsing.h"
#include "utils.h"
#include "init.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

t_obj	*object(t_obj_type type, void *element, t_color3 albedo)
{
	t_obj	*new;

	new = malloc(sizeof(t_obj));
	if (new == NULL)
		exit(1);
	new->type = type;
	new->element = element;
	new->albedo = albedo;
	new->next = NULL;
	return (new);
}

void	close_fds(int fd[])
{
	close(fd[0]);
	close(fd[1]);
}
