/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:39:50 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 11:45:18 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"
#include "../maths/maths.h"
#include "../world/world.h"

t_point3d	ft_get_pixel(t_world *world, int x, int y)
{
	t_vector3d	pixel;
	t_vector3d	temp;
	t_point3d	resul;
	double		scalar_x;
	double		scalar_y;

	scalar_x = x * world->projection->hpixel;
	scalar_y = y * world->projection->vpixel;


//	pixel = ft_sum_vect((t_vector3d)world->projection->origin,ft_product_vect_scalar(world->camera->right, scalar_x));

	pixel = ft_product_vect_scalar(world->camera->right, scalar_x);
	temp.x = world->projection->origin.x;
	temp.y = world->projection->origin.y;
	temp.z = world->projection->origin.z;
	
	pixel = ft_sum_vect(temp, pixel);
	
	pixel = ft_rest_vect(pixel,ft_product_vect_scalar(world->camera->up, scalar_y));
	resul.x = pixel.x;
	resul.y = pixel.y;
	resul.z = pixel.z;
	return (resul);
}

t_ray	*ft_get_ray(t_world *world, int x, int y)
{
	t_point3d	pixel;
	t_ray		*ray;
	t_vector3d	temp;
	t_vector3d	pixevect;
	ray = malloc(sizeof(*ray));
	if (!ray)
		return(NULL);

	pixel = ft_get_pixel(world, x, y);
	ray->origin = world->camera->eye;
	temp.x = ray->origin.x;
	temp.y = ray->origin.y;
	temp.z = ray->origin.z;
	
	pixevect.x = pixel.x;
	pixevect.y = pixel.y;
	pixevect.z = pixel.z;

	ray->direction = ft_rest_vect(pixevect, temp);
	ray->direction = ft_sum_vect(ft_normalize(ray->direction), temp);
			
	return (ray);
}


void	ft_render(t_ambient *amb, t_object *obj,t_world *world)
{
	int	x;
	int	y;
	int	colour;
	int	type;
	t_ray	*ray;
	
	type = 0;
	y = 0;
	colour = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
	//		colour = ft_samplers(&ray,(float)x, (float)y);
			ray = ft_get_ray(world, x, y);
			
			//proba si funciona 
			type = ft_intersects(amb, obj, ray);
			if (type != 0)
			{
				ft_my_mlx_pxput(world->mlx, x, y, colour);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(world->mlx->mlx, world->mlx->mlx_win, world->mlx->img, 0, 0);
	(void)amb;
	(void)obj;
	(void)ray;
}
