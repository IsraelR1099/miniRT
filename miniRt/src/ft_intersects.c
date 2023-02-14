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
	double		t;
	double		p;
	int		pla;
	int		esfera;

	t = 0.0;
	p = 0.0;
	pla = ft_inter_plane(amb, obj, ray_dir, &p);	
	esfera = ft_inter_sphere(amb, obj, ray_dir, &t);
	
	if (esfera && pla)	
	{
		if (t < p)
			return(sp);
		else
			return(pl);
	}	
	if (pla)
		return(pl);
	if (esfera)
		return(sp);
	return (0);
}
