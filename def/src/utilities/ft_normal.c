/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:49:08 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/26 11:47:35 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaderec.h"

t_normal	ft_vect_normal_sphere(t_sphere *sphere, t_point3d hit_point)
{
	t_vector3d	center_sph;
	t_vector3d	hit_p;
	t_vector3d	rest;
	t_normal	ret;
	double		magnitude;

	center_sph.x = sphere->x;
	center_sph.y = sphere->y;
	center_sph.z = sphere->z;
	hit_p.x = hit_point.x;
	hit_p.y = hit_point.y;
	hit_p.z = hit_point.z;
	rest = ft_rest_vect(hit_p, center_sph);
	magnitude = sqrt(rest.x * rest.x + rest.y * rest.y
			+ rest.z * rest.z);
	ret.x = rest.x / magnitude;
	ret.y = rest.y / magnitude;
	ret.z = rest.z / magnitude;
	ret.x *= -1;
	ret.y *= -1;
	ret.z *= -1;
	return (ret);
}

t_vector3d	ft_normalize(t_vector3d vector)
{
	double		magnitude;
	t_vector3d	normal;

	magnitude = sqrt(vector.x * vector.x + vector.y * vector.y
			+ vector.z * vector.z);
	normal.x = vector.x;
	normal.y = vector.y;
	normal.z = vector.z;
	normal.x /= magnitude;
	normal.y /= magnitude;
	normal.z /= magnitude;
	return (normal);
}

t_normal	ft_vect_normal_cyl(t_cylinder *cylon, t_point3d hit_point)
{
/*
	t_normal normal;


if (hit_point.y >= (cylon->y + cylon->height / 2)) {
    normal.x = 0;
	normal.y = 1;
	normal.z = 0;
	//normal cap amunt
	return(normal);
} else if (hit_point.y <= (cylon->y - cylon->height / 2)) {
    normal.x = 0;
	normal.y = -1;
	normal.z = 0;
	// Normal cap avall
	return(normal);
}

    // Calcula las componentes x y z de la normal en el punto de intersección
    normal.x = hit_point.x - cylon->x;
    normal.y = 0.0; // La normal de un cilindro es perpendicular a su eje, que es paralelo al ej:
    normal.z = hit_point.z - cylon->z;
    // Normaliza el vector de la normal
    float magnitude = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
    normal.x /= magnitude;
    normal.y /= magnitude;
    normal.z /= magnitude;
    return (normal);
}
*/

	 t_vector3d  point;
      t_vector3d  hit;
      t_vector3d  center;
      t_normal    ret;
      double      radius;

if (hit_point.y >= (cylon->y + cylon->height / 2)) {
    ret.x = 0;
	ret.y = 1;
	ret.z = 0;
	//normal cap amunt
	return(ret);
} else if (hit_point.y <= (cylon->y - cylon->height / 2)) {
    ret.x = 0;
	ret.y = -1;
	ret.z = 0;
	// Normal cap avall
	return(ret);
}
      center.x = cylon->x;
     center.y = cylon->y;
      center.z = cylon->z;
      hit.x = hit_point.x;
     hit.y = hit_point.y;
      hit.z = hit_point.z;
      point = ft_rest_vect(hit, center);
      radius = cylon->diameter / 2;
      point.x = point.x * radius;
      point.y = 0.0;
      point.z = point.z * radius;
      point = ft_normalize(point);
	  ret.x = point.x;
      ret.y = point.y;
     ret.z = point.z;
	  return (ret);
}
/*	 

	t_vector3d	center_cyl;
	t_vector3d	hit_p;
	t_vector3d	rest;
	t_normal	ret;
	double		magnitude;

	center_cyl.x = cylon->x;
	center_cyl.y = cylon->y;
	center_cyl.z = cylon->z;
	hit_p.x = hit_point.x;
	hit_p.y = hit_point.y;
	hit_p.z = hit_point.z;
	rest = ft_rest_vect(hit_p, center_cyl);
	magnitude = sqrt(rest.x * rest.x + rest.y * rest.y
			+ rest.z * rest.z);
	ret.x = rest.x / magnitude;
	ret.y = rest.y / magnitude;
	ret.z = rest.z / magnitude;
	ret.x *= -1;
	ret.y *= -1;
	ret.z *= -1;
	return (ret);

	}
*/

