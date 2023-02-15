/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:05:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/15 12:51:50 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

static double	ft_a_value(t_vector ray_dir)
{
	return (ft_dot_product_vect(ray_dir, ray_dir));
}

static double	ft_b_value(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	t_cam		*cam;
	t_sphere	*sphere;
	t_vector	sphere_pos;
	t_vector	cam_pos;
	t_vector	res_cam_sphere;

	cam = (t_cam *)ft_find_lst(amb, C);
	cam_pos.x = cam->x;
	cam_pos.y = cam->y;
	cam_pos.z = cam->z;
	sphere = (t_sphere *)ft_find_lst_obj(obj, sp);
	sphere_pos.x = sphere->x;
	sphere_pos.y = sphere->y;
	sphere_pos.z = sphere->z;
	res_cam_sphere = ft_rest_vect(cam_pos, sphere_pos);
	if (ft_dot_product_vect(ray_dir, res_cam_sphere) < 0)
		return(0);
	return (2 * ft_dot_product_vect(ray_dir, res_cam_sphere));
}

static double	ft_c_value(t_ambient *amb, t_object *obj)
{
	t_vector	res_cam_sph;
	t_vector	cam_pos;
	t_vector	sphere_pos;
	t_cam		*cam;
	t_sphere	*sphere;

	cam = (t_cam *)ft_find_lst(amb, C);
	cam_pos.x = cam->x;
	cam_pos.y = cam->y;
	cam_pos.z = cam->z;
	sphere = (t_sphere *)ft_find_lst_obj(obj, sp);
	sphere_pos.x = sphere->x;
	sphere_pos.y = sphere->y;
	sphere_pos.z = sphere->z;
	res_cam_sph = ft_rest_vect(cam_pos, sphere_pos);
	return (ft_dot_product_vect(res_cam_sph, res_cam_sph) - ((sphere->diameter / 2) * (sphere->diameter / 2)));	
}

static double	ft_calc_t(double scalar_a, double scalar_b, double scalar_c, double *t)
{
	double	temp;
	double	t1;
	double	t0;
	double	temp2;
	double	ret;

	ret = scalar_b * scalar_b - (4 * scalar_a * scalar_c);
	if (ret < 0.0)
		return (0);
	temp = scalar_b * scalar_b - (4 * scalar_a * scalar_c);
	t1 = (-scalar_b + sqrt(temp)) / (2 * scalar_a);
	t0 = (-scalar_b - sqrt(temp)) / (2 * scalar_a);
/*
	if (t0 < 0 && t1 < 0 )
		return (0);
	else if (t0 <= 0.0)
		t0 = t1;
	else if (t1 <= 0.0)
		t1 = t0;
	 *t = ft_min_double(t0, t1);
	return(1);
	*/

	if (t0 > t1) 
    	{
		temp2 = t0;
		t0 = t1;
		t1 = temp2;
		if (t0 < 0.0) 
		{
			t0 = t1;
		}
		if (t0 < 0.0)
		{
			return (0);
		}
	}
		*t = (t0);
    	//*t = fabs(t0);
    	return (1);
		

}

int	ft_inter_sphere(t_ambient *amb, t_object *obj, t_vector ray_dir, double *t)
{
	double	scalar_a;
	double	scalar_b;
	double	scalar_c;
	
	scalar_a = ft_a_value(ray_dir);
	scalar_b = ft_b_value(amb, obj, ray_dir);
	scalar_c = ft_c_value(amb, obj);
	return(ft_calc_t(scalar_a, scalar_b, scalar_c, t));
}
