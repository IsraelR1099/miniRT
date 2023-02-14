/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/10 11:58:07 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

t_vector getRayDirection(int j, int i, double pixelwidth, double pixelheight) 
{
	t_vector	result;

	result.x = (j- WIDTH / 2) * pixelwidth ; 
	result.y = (HEIGHT / 2 - i) * pixelheight;
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
		
			type = ft_intersects(amb, obj, ray_dir);
			if (type == sp)
			{
				ft_my_mlx_pxput(mlx, j, i, colours.c_sphere);
				k++;
			}
			else if (type == pl)
				ft_my_mlx_pxput(mlx, j, i, colours.c_plane);
			else if (type == cy)
				ft_my_mlx_pxput(mlx, j, i, colours.c_cylinder);
			else
				ft_my_mlx_pxput(mlx, j, i, colours.c_ambient);
		//	ft_my_mlx_pxput(mlx, j, i, ft_colour_value(amb, A));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
