/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_reflective.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:46:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/10 10:40:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

//Shoot another ray from the hit point to the direction of wi (reflected)
//L (phong trace) + fr * new_trace * dotnwi
/*t_rgb	ft_shade_reflective(t_world *world, t_shaderec *shade)
{
	t_rgb		new_trace_total;
	t_vector3d	normal;
	t_rgb		l;
	t_rgb		ret;
	t_vector3d	wi;

	l = ft_shade_phong(world, shade);
	normal = ft_normal_vector3d(shade);
	new_trace_total = ft_ray_cast(world, shade, &wi, normal);
	ret = ft_rgb_sum(l, new_trace_total);
	printf("color al final es r %f, g %f, b %f\n", ret.r, ret.g, ret.b);
	exit(1);
	if (ret.r > 1 || ret.g > 1 || ret.b > 1)
		ret = ft_max_to_one(ret);
	return (ret);
}*/

t_rgb	ft_shade_reflective(t_world *world, t_shaderec *shade)
{
	t_rgb		l;
	t_rgb		fr;
	t_rgb		sample_f;
	t_rgb		new_trace;
	t_vector3d	wo;
	t_vector3d	wi;
	t_ray		reflective_ray;
	double		dotnwi;

	wo.x = shade->ray.direction.x * (-1);
	wo.y = shade->ray.direction.y * (-1);
	wo.z = shade->ray.direction.z * (-1);
	l = ft_shade_phong(world, shade);
	sample_f = ft_reflective_f(shade, wo, &wi);
	reflective_ray.origin = shade->hit_point;
	reflective_ray.direction = wi;
	new_trace = ft_trace_reflective(world, &reflective_ray);
	//new_trace = ft_ray_cast(world, shade, &wi);
	fr = ft_rgb_product_vect(sample_f, new_trace);
	dotnwi = ft_dot_product_vect(ft_normal_vector3d(shade), wi);
	fr = ft_rgb_scalar_product(fr, dotnwi);
	l = ft_rgb_sum(l, fr);
	if (l.r > 1 || l.g > 1 || l.b > 1)
		l = ft_max_to_one(l);
	return (l);
}
