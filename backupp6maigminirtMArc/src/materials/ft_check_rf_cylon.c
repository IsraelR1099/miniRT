/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects_cylon.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:55:59 by msoler-e          #+#    #+#             */
/*   Updated: 2023/05/10 13:29:45 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"
#define EPSILON 1e-4


double	caps_intersection_return(double id[2],
	t_ray ray, t_cylinder cylon, t_vector3d c2)
{
	t_vector3d	ray_orig;
	t_vector3d	ip1;
	t_vector3d	ip2;
	t_vector3d	cyl_center;

	cyl_center.x = cylon.x;
	cyl_center.y = cylon.y;
	cyl_center.z = cylon.z;
	ft_ray_origin(ray, &ray_orig);
	ip1 = ft_sum_vect(ray_orig, ft_product_vect_scalar(ray.direction, id[0]));
	ip2 = ft_sum_vect(ray_orig, ft_product_vect_scalar(ray.direction, id[1]));
	if ((id[0] != -1 && distance(ip1, cyl_center) <= cylon.diameter / 2)
		&& (id[1] != -1 && distance(ip2, c2) <= cylon.diameter / 2))
	{	
		if (id[0] < id[1])
			return (id[0]);
		else
			return (id[1]);
	}
	else if (id[0] != -1 && distance(ip1, cyl_center) <= cylon.diameter / 2)
		return (id[0]);
	else if (id[1] != -1 && distance(ip2, c2) <= cylon.diameter / 2)
		return (id[1]);
	//no tinc clar hagi de ser -1)
	return (-1);
}

double	caps_intersection(t_ray ray, t_cylinder cylon,
		t_vector3d c2)
{
	double		id[2];
	t_vector3d	ray_orig;
	t_vector3d	cyl_normal;
	t_vector3d	cyl_center;

	ray_orig.x = ray.origin.x;
	ray_orig.y = ray.origin.y;
	ray_orig.z = ray.origin.z;
	ft_cyl_center_normal_rad(cylon, &cyl_normal, &cyl_center);
	id[0] = solve_plane(ray_orig, ray.direction, cyl_center, cyl_normal);
	id[1] = solve_plane(ray_orig, ray.direction, c2, cyl_normal);
	if (id[0] != -1 || id[1] != -1)
		return (caps_intersection_return(id, ray, cylon, c2));
	return (-1);
}

void	check_t(double *t, t_cylinder cylon, t_ray ray)
{
	t_vector3d	q;
	t_vector3d	p2;
	t_vector3d	cyl_normal;
	t_vector3d	cyl_center;
	t_vector3d	ray_orig;

	ft_cyl_center_normal_rad(cylon, &cyl_normal, &cyl_center);
	ray_orig.x = ray.origin.x;
	ray_orig.y = ray.origin.y;
	ray_orig.z = ray.origin.z;
	p2 = ft_sum_vect(cyl_center,
			ft_product_vect_scalar(cyl_normal, cylon.height));
	q = ft_sum_vect(ray_orig, ft_product_vect_scalar(ray.direction, *t));
	if (caps_intersection(ray, cylon, p2) == -1)
	{
		if (ft_dot_product_vect(cyl_normal, ft_rest_vect(q, cyl_center)) <= 0)
			*t = -1;
		if (ft_dot_product_vect(cyl_normal, ft_rest_vect(q, p2)) >= 0)
			*t = -1;
	}
	else
		*t = caps_intersection(ray, cylon, p2);
}

int	solve_quadratic(double quadratic[3], double *x0, double *x1)
{
	double	discr;
	double	q;

	discr = pow(quadratic[1], 2) - 4 * quadratic[0] * quadratic[2];
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * quadratic[1] / quadratic[0];
		*x1 = -0.5 * quadratic[1] / quadratic[0];
	}
	else
	{
		if (quadratic[1] > 0)
			q = -1 * (quadratic[1] + sqrt(discr)) / 2;
		else
			q = -1 * (quadratic[1] - sqrt(discr)) / 2;
		*x0 = q / quadratic[0];
		*x1 = quadratic[2] / q;
	}
	if (*x0 > *x1)
		swap_doubles(x0, x1);
	return (1);
}

double	ft_get_cylon(double *t0, double *t1, t_cylinder cylon, t_ray ray)
{
	t_vector3d	a_sqrt;
	t_vector3d	right;
	t_vector3d	cyl_normal;
	t_vector3d	cyl_center;
	t_vector3d	ray_orig;
	double		quadratic[3];

	ft_cyl_center_normal_rad(cylon, &cyl_normal, &cyl_center);
	ft_ray_origin(ray, &ray_orig);
	a_sqrt = ft_rest_vect(ray.direction, ft_product_vect_scalar(cyl_normal,
				ft_dot_product_vect(ray.direction, cyl_normal)));
	quadratic[0] = ft_dot_product_vect(a_sqrt, a_sqrt);
	right = ft_rest_vect(ft_rest_vect(ray_orig, cyl_center),
			ft_product_vect_scalar(cyl_normal,
				ft_dot_product_vect(ft_rest_vect(ray_orig,
						cyl_center), cyl_normal)));
	quadratic[1] = 2 * ft_dot_product_vect(a_sqrt, right);
	quadratic[2] = ft_dot_product_vect(right, right)
		- ((cylon.diameter / 2) * (cylon.diameter / 2));
	if (!solve_quadratic(quadratic, t0, t1))
		return (0);
	return (1);
}

double	ft_check_rf_cylon(t_cylinder cylon, t_ray ray)
{
	double	t0;
	double	t1;
	double	t;

	t = 0;
	if (!ft_get_cylon(&t0, &t1, cylon, ray))
		return (0);
	if (t0 > 0)
		check_t(&t0, cylon, ray);
	if (t1 > 0)
		check_t(&t1, cylon, ray);
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t1 < t0)
	{
		if (t1 > 0)
			t = t1;
		else
			t = t0;
	}
	else
	{
		if (t0 > 0)
			t = t0;
		else
			t = t1;
	}
	return (t);
}
