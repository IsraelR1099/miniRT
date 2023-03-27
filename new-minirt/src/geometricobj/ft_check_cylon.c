/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects_cylon.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:55:59 by msoler-e          #+#    #+#             */
/*   Updated: 2023/03/24 13:24:49 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobj.h"


static double   ft_a_value(t_ray *ray, t_cylinder *cylon)
{
        float           temp;
        float           temp2;
        t_vector3d      normal;
   
        normal.x = cylon->x_normal; 
        normal.y = cylon->y_normal;
        normal.z = cylon->z_normal;
        temp = ft_dot_product_vect(ray->direction, ray->direction);
        temp2 = ft_dot_product_vect(ray->direction, normal);
        temp2 = temp2 * temp2;
	return(temp - temp2);
}

static double   ft_b_value(t_ray *ray, t_cylinder *cylon)
{
	float		temp;
	float		temp2;
	t_vector3d	oc;
	t_vector3d	center;
	t_vector3d	normal;
	t_vector3d	origin;

        normal.x = cylon->x_normal; 
        normal.y = cylon->y_normal;
        normal.z = cylon->z_normal;
	center.x = cylon->x;
	center.y = cylon->y;
	center.z = cylon->z;
	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	oc = ft_rest_vect(origin, center);
	temp = 2 * ft_dot_product_vect(ray->direction, oc);
	temp2 = (ft_dot_product_vect(ray->direction, normal)) * (ft_dot_product_vect(oc, normal));
	return(temp - temp2);
}

static double   ft_c_value(t_ray *ray, t_cylinder *cylon)
{

	float		temp;
	float		temp2;
	float		temp3;
	t_vector3d	oc;
	t_vector3d	center;
	t_vector3d	normal;
	t_vector3d	origin;
	
        normal.x = cylon->x_normal; 
        normal.y = cylon->y_normal;
        normal.z = cylon->z_normal;
	center.x = cylon->x;
	center.y = cylon->y;
	center.z = cylon->z;
	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	oc = ft_rest_vect(origin, center);
	temp = ft_dot_product_vect(oc, oc);
	temp2 = ft_dot_product_vect(oc, normal);
	temp2 = temp2 * temp2;
	temp3 = (cylon->diameter/2)*(cylon->diameter/2);
	temp2 = (temp2 - temp3);
	return(temp - temp2);
}
/*
static double   ft_h_value(t_vector ray_dir, t_object *obj, t_ambient *amb, float t)
{

        float           h;
        t_cylinder      *cylon;
        t_vector        cylon_normal;
        t_vector        cylon_center;
        t_cam           *cam;
        t_vector        cam_pos;

        cylon = (t_cylinder *)ft_find_lst_obj(obj, cy);
        cylon_normal.x = cylon->x_normal;
        cylon_normal.y = cylon->y_normal;
        cylon_normal.z = cylon->z_normal;

        cylon_center.x = cylon->x;
        cylon_center.y = cylon->y;
        cylon_center.z = cylon->z;

        cam = (t_cam *)ft_find_lst(amb, C);
        cam_pos.x = cam->x; 
        cam_pos.y = cam->y; 
        cam_pos.z = cam->z;

        h = (cam_pos.x + t * ray_dir.x - cylon_center.x) * cylon_normal.x +
            (cam_pos.y + t * ray_dir.y - cylon_center.y) * cylon_normal.y +
            (cam_pos.z + t * ray_dir.z - cylon_center.z) * cylon_normal.z;
        return (h);
}
*/
// Funció per calcular la intersecció d'un raig amb un cilindre
double	ft_check_cylon(t_cameras *camera, t_cylinder *cylon, t_ray *ray)
{
(void)camera;

	double  scalar_a;
	double	scalar_b;
	double	scalar_c;
	double	discr;
	double	y1;
	double	y2;
	double	t1;
	double	t2;

	scalar_a = ft_a_value(ray,cylon);
	scalar_b = ft_b_value(ray,cylon);
	scalar_c = ft_c_value(ray,cylon);
	discr = (scalar_b * scalar_b) - ( 4 * scalar_a * scalar_c);
	if (discr < 0)
	{
		return(0);	
	}	
	t1 = (-scalar_b - sqrt(discr)) / (2 * scalar_a);
	t2 = (-scalar_b + sqrt(discr)) / (2 * scalar_a);

	y1 = ray->origin.y + (t1 * ray->direction.y);
	y2 = ray->origin.y + (t2 * ray->direction.y);
	if ((y1 < cylon->y) || (y1 > cylon->y + cylon->height/2))
       	{
        // El punto de intersección está fuera del cilindro.
        t1 = INFINITY;
    	}

    if ((y2 < cylon->y) || (y2 > cylon->y + cylon->height/2)) 
    {
        // El punto de intersección está fuera del cilindro.
        t2 = INFINITY;
    }

    if ((t1 > 0) && (t2 > 0)) 
    {
        // Ambos puntos de intersección están delante del origen del rayo.
        if (t1 > t2)
	{
		printf("t2=%f\n",y2);
		return(y2);
	}
	else
	{
		printf("t1=%f\n",y1);
		return (y1);
	}
    }

    // El rayo no intersecta el cilindro.
    return 0;
}
