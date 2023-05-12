/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects_cylon.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:55:59 by msoler-e          #+#    #+#             */
/*   Updated: 2023/05/12 12:05:43 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights.h"
#define	EPSILON 1e-4

static double	distance(const t_vector3d p1, const t_vector3d p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2)));
}

static double	solve_plane(t_vector3d o, t_vector3d d, t_vector3d plane_p, t_vector3d plane_nv)
{
	double	x;
	double	denom;

	denom = ft_dot_product_vect(plane_nv, d);
	if (denom == 0)
		return (-1);
	x = (ft_dot_product_vect(plane_nv, ft_rest_vect(plane_p, o))) / denom;
	if (x > EPSILON)
		return(x);
	else	
		return(-1);
}


static double	caps_intersection(t_ray ray, t_vector3d cyl_center, t_vector3d cyl_normal, t_vector3d c2, double radius)
{
	double		id1;
	double		id2;
	t_vector3d	ip1;
	t_vector3d	ip2;
	t_vector3d	ray_orig;

	ray_orig.x = ray.origin.x;
	ray_orig.y = ray.origin.y;
	ray_orig.z = ray.origin.z;

	id1 = solve_plane(ray_orig, ray.direction, cyl_center, cyl_normal);
	id2 = solve_plane(ray_orig, ray.direction, c2, cyl_normal);
	if (id1 != -1 || id2 != -1)
	{
		ip1 = ft_sum_vect(ray_orig, ft_product_vect_scalar(ray.direction, id1));
		ip2 = ft_sum_vect(ray_orig, ft_product_vect_scalar(ray.direction, id2));
		if ((id1 != -1 && distance(ip1, cyl_center) <= radius) && (id2 != -1 && distance(ip2, c2) <= radius))
			return (id1 < id2 ? id1 : id2);
		else if (id1 != -1 && distance(ip1, cyl_center) <= radius)
			return (id1);
		else if (id2 != -1 && distance(ip2, c2) <= radius)
			return (id2);
	}
	return (-1);
}

static void		check_t(double *t, t_cylinder cylon, t_ray ray)
{
	t_vector3d	q;
	t_vector3d	p2;
	t_vector3d	cyl_normal;
	t_vector3d	ray_orig;
	t_vector3d	cyl_center;
	double		t2;
	double		radius;

	cyl_center.x = cylon.x;
	cyl_center.y = cylon.y;
	cyl_center.z = cylon.z;
	cyl_normal.x = cylon.x_normal;
	cyl_normal.y = cylon.y_normal;
	cyl_normal.z = cylon.z_normal;
	ray_orig.x = ray.origin.x;
	ray_orig.y = ray.origin.y;
	ray_orig.z = ray.origin.z;
	radius = cylon.diameter/2;
	p2 = ft_sum_vect(cyl_center, ft_product_vect_scalar(cyl_normal, cylon.height));
	q = ft_sum_vect(ray_orig, ft_product_vect_scalar(ray.direction, *t));
	t2= caps_intersection(ray, cyl_center, cyl_normal, p2, radius);
	if ( t2 == -1)
	{
		if (ft_dot_product_vect(cyl_normal, ft_rest_vect(q, cyl_center)) <= 0)
			*t = -1;
		if (ft_dot_product_vect(cyl_normal, ft_rest_vect(q, p2)) >= 0)
			*t = -1;
	}else
		*t = t2;
	(void)radius;
}

static void		swap_doubles(double *a, double *b)
{
	double buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

static int	solve_quadratic(double a, double b, double c, double *x0, double *x1)
{
	double discr;
	double q;

	discr = pow(b, 2) - 4 * a * c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * b / a;
		*x1 = -0.5 * b / a;
	}
	else
	{
		if (b > 0)
			q = -1 * (b + sqrt(discr)) / 2;
		else
			q = -1 * (b - sqrt(discr)) / 2;
		*x0 = q / a;
		*x1 = c / q;
	}
	if (*x0 > *x1)
		swap_doubles(x0, x1);
	return (1);
}

static double	ft_get_cylon(double *t0, double *t1, t_cylinder cylon, t_ray ray)
{
	t_vector3d	a_sqrt;
	t_vector3d	right;
	t_vector3d	cyl_normal;
	t_vector3d	cyl_center;
	t_vector3d	ray_orig;
	double		a;
	double		b;
	double		c;
	double 		radius;

	cyl_normal.x = cylon.x_normal;
	cyl_normal.y = cylon.y_normal;
	cyl_normal.z = cylon.z_normal;
	cyl_center.x = cylon.x;
	cyl_center.y = cylon.y;
	cyl_center.z = cylon.z;
	ray_orig.x = ray.origin.x;
	ray_orig.y = ray.origin.y;
	ray_orig.z = ray.origin.z;

	a_sqrt = ft_rest_vect(ray.direction,ft_product_vect_scalar(cyl_normal,
				ft_dot_product_vect(ray.direction, cyl_normal)));
	a = ft_dot_product_vect(a_sqrt, a_sqrt);
	right = ft_rest_vect(ft_rest_vect(ray_orig, cyl_center),ft_product_vect_scalar(cyl_normal,ft_dot_product_vect(ft_rest_vect(ray_orig, cyl_center),cyl_normal)));
	b = 2 * ft_dot_product_vect(a_sqrt, right);
	radius = cylon.diameter/2;
	c = ft_dot_product_vect(right, right) - (radius * radius);
	if (!solve_quadratic(a, b, c, t0, t1))
		return (0);
	return (1);
}
double	ft_hit_cylon(t_cylinder cylon, t_ray ray)
{
	double t0;
	double t1;
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
		if (t1 > 0)
			t = t1;
		else
			t = t0;
	else
	{
		if (t0 > 0)
			t = t0;
		else
			t = t1;
	}
	return (t);
}
