/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projectionwin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:08:43 by msoler-e          #+#    #+#             */
/*   Updated: 2023/03/08 13:07:43 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../maths/maths.h"
#include "cameras.h"

t_projection	*ft_build_plane_projection(t_cameras *camera, t_projection *planeproj)
{
	float	tempw;
	float	temph;
	t_vector3d	vectempw;
	t_vector3d	vectemph;
	
	planeproj.hsize = 2 * camera.dis * tan(fov/2);
	planeproj.vsize = 2 * camera.dis * tan(fov/2);
	tempw = ((WIDTH - 1) / 2) * planeproj.hsize;
	vectempw = ft_product_vect_scalar(camera.right , tempw)
	temph = ((HEIGHT -1) / 2) * planeproj.vsize:
	vectemph = ft_product_vect_scalar(camera.right , tempw)
	planeproj.origin = ft_rest_vect(camera.center, (ft_sum_vect(vectempw, vectemph));
	hpixel = planeproj.hsize / WIDTH;
	vpixel = planeproj.vsize / HEIGHT;
	return (planeproj);
}
