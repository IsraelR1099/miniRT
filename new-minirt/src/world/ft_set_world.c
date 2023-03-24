/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:26:19 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/24 11:06:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_vp	ft_set_vp(void)
{
	t_vp	vp;

	vp.num_samples = 16;
	vp.color.r = 0;
	vp.color.g = 0;
	vp.color.b = 0;
	return (vp);
}

void	ft_set_world(t_ambient *amb, t_object *obj, t_world *world)
{
	world->camera = ft_build_camera(amb);
	world->amb = amb;
	world->obj = obj;
	world->vp = ft_set_vp();
}
