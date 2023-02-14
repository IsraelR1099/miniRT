/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:38:13 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/10 13:15:07 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	ft_inter_plane(t_ambient *amb, t_object *obj, t_vector ray_dir, double *t)
{
	t_vector	normal_plane;
	t_plane		*plane;
	t_cam           *cam;
        t_vector        cam_pos;
	t_vector        point_plane;
	double		ret;

	plane = (t_plane *)ft_find_lst_obj(obj, pl);
	normal_plane.x = plane->x_normal;
	normal_plane.y = plane->y_normal;
	normal_plane.z = plane->z_normal;
	point_plane.x = plane->x;
        point_plane.y = plane->y;
        point_plane.z = plane->z;

	cam = (t_cam *)ft_find_lst(amb, C);
        cam_pos.x = cam->x;
        cam_pos.y = cam->y;
        cam_pos.z = cam->z;
	/*
	float denom = ft_dot_product_vect(normal_plane, ray_dir);
	if (fabs(denom) > 1e-6) 
	{
		printf("denom%f",denom);
		t_vector p0l0 = {point_plane.x - cam_pos.x,
                 point_plane.y - cam_pos.y,
                 point_plane.z - cam_pos.z};
    		*t = ft_dot_product_vect(p0l0, normal_plane) / denom;
    		printf("Lat=%f",*t);
		return (*t >= 0);

  	}
 	 return 0;
	 */
	ret = ft_dot_product_vect(normal_plane, ft_rest_vect(point_plane, cam_pos)) / ft_dot_product_vect(normal_plane, ray_dir);
	if (ret >= 0)
		return(0);
	else
	{
		*t = ret;
		return(1);
	}
}
