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

void	ft_generate(t_ambient *amb, t_object *obj, t_window *mlx)
{
	int			i;
	int			j;
	int			t;
	float		len;
	t_vector	ray_dir;
	int			type;
	t_colours	colours;

	i = 0;
	t = 300;
	len = 0;
	ft_set_colour(amb, obj, &colours, 6);
	int k = 0;
	(void)t;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			//calculate ray direction

			ray_dir.x = (j- WIDTH / 2) ; 
			ray_dir.y = (i -HEIGHT /2 ) * (RATIO);
			ray_dir.z = -1 * t;
			/*
			ray_dir.x = (2 * (j + 0.5) / WIDTH - 1) * RATIO;
        		ray_dir.y = 1 - 2 * (i + 0.5) / HEIGHT;
			ray_dir.z = -1 *t;
	
			ray_dir.x = (j / WIDTH  -0.5); 
			ray_dir.y = (i / HEIGHT -0.5);
			ray_dir.z = -1 * t;
	
			ray_dir.x = (j- WIDTH / 2) ; 
			ray_dir.y = (i -HEIGHT /2 ) * (RATIO);
			ray_dir.z = -1 * t;
	
			ray_dir.x = (2 * ((i + 0.5) / WIDTH) -1) * RATIO;
			ray_dir.y = (1 - 2 * ((j + 0.5) / HEIGHT));
			ray_dir.z = -1 * t;
	*/		
			//normalize direction vector
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
	(void)len;
}
