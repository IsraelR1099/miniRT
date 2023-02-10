/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:36:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/10 13:15:34 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

int	ft_intersects(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	double	t_sphere;
	double	t_plane;
	//double	t_cyl;

	t_sphere = ft_inter_sphere(amb, obj, ray_dir);
	t_plane = ft_inter_plane(amb, obj, ray_dir);
	if ( t_sphere == 2 && t_plane == 2)
		return (A);
	if ((t_plane > t_sphere) || ( t_sphere == 2))
		return (pl); 
	if ((t_plane < t_sphere) || ( t_plane  == 2))
		return (sp);
	return (0);
}
