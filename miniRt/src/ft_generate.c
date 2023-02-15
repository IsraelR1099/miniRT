/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/15 12:51:53 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

t_vector getRayDirection(int j, int i, double pixelwidth, double pixelheight) 
{
	t_vector	result;

	result.x = ( WIDTH / 2 -j) * pixelwidth ; 
	result.y = (i-HEIGHT / 2 ) * pixelheight;
	result.z = -1;

  return (result);
}

void	ft_generate(t_ambient *amb, t_object *obj, t_window *mlx)
{
	int		i;
	int		j;
	int		k;
	double		pixelwidth;
	double		pixelheight;
	t_cam		*cam;
	t_vector	ray_dir;
	t_vector	ray_pos;
	int		type;
	t_colours	colours;

	cam = (t_cam *)ft_find_lst(amb, C);
	i = 0;
	k = 0;
	ft_set_colour(amb, obj, &colours, 6);
	pixelwidth = tan(cam->fov / 2.0 * M_PI / 180.0) * RATIO / WIDTH;
	pixelheight = tan(cam->fov / 2.0 * M_PI / 180.0) / HEIGHT;
	
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ray_dir = getRayDirection(j, i,pixelwidth,pixelheight);
			ft_normalize(ray_dir);
			ray_pos.x = cam->x_normal;
			ray_pos.y = cam->y_normal;
			ray_pos.z = cam->z_normal;

			ray_pos = add(ray_pos, mul(ray_dir,0.5));	
			
			type = ft_intersects(amb, obj, ray_pos);

			if (type == cy)
				ft_my_mlx_pxput(mlx, j, i, colours.c_cylinder);
			if (type == sp)
			{
				ft_my_mlx_pxput(mlx, j, i, colours.c_sphere);
				k++;
			}
			else if (type == pl)
				ft_my_mlx_pxput(mlx, j, i, colours.c_plane);
			//else if (type == cy)
			//	ft_my_mlx_pxput(mlx, j, i, colours.c_cylinder);
			else
				ft_my_mlx_pxput(mlx, j, i, colours.c_ambient);
		//	ft_my_mlx_pxput(mlx, j, i, ft_colour_value(amb, A));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
