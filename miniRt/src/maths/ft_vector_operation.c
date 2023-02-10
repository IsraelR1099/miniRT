/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:05:48 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/10 10:28:17 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"

double	ft_dot_product_vect(t_vector vector_left, t_vector vector_right)
{
	float	x;
	float	y;
	float	z;
	float	ret;

	x = vector_left.x * vector_right.x;
	y = vector_left.y * vector_right.y;
	z = vector_left.z * vector_right.z;
	ret = x + y + z;
	return (ret);
}

t_vector	ft_rest_vect(t_vector origin, t_vector obj)
{
	t_vector	ret;

	ret.x = origin.x - obj.x;
	ret.y = origin.y - obj.y;
	ret.z = origin.z - obj.z;
	return (ret);
}
t_vector	ft_normalize(t_vector ray_dir)
{
	float	len;

	len = sqrt(ft_dot_product_vect(ray_dir, ray_dir));
	ray_dir.x /= len;
	ray_dir.y /= len;
	ray_dir.z /= len;
	return (ray_dir);
}