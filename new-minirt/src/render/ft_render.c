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

t_ray	ft_get_ray(t_world world, int x, int y)
{
	t_point3d	pixel:
	t_ray		*ray:

	ray = malloc(sizeof(*ray));
	if (!ray)
		return (NULL);


}


void	ft_render(t_ambient *amb, t_object *obj,t_world *world)
{
	int	x;
	int	y;
	int	colour;
	t_ray	*ray;

	y = 0;
	colour = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
	//		colour = ft_samplers(&ray,(float)x, (float)y);
			ray = ft_get_ray(world,x,y);
			ft_my_mlx_pxput(world->mlx, x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(world->mlx->mlx, world->mlx->mlx_win, world->mlx->img, 0, 0);
	(void)amb;
	(void)obj;
}
