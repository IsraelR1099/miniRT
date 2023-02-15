/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:36:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/15 12:51:57 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

int	ft_intersects(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	double		t;
	double		p;
	double		q;
	int		pla;
	int		esfera;
	int		cylon;

	t = 0.0;
	p = 0.0;
	q = 0.0;
	pla = ft_inter_plane(amb, obj, ray_dir, &p);	
	esfera = ft_inter_sphere(amb, obj, ray_dir, &t);
	cylon = ft_intersect_cylon(amb, obj, ray_dir, &q);
	//if (cylon)
	//	return(cy);	
	if (esfera && pla)	
	{
		if (t < p)
			return(sp);
		else
		{
	//		printf("la distancia al pla es:%f",p);
			return(pl);
		}
	}	
	if (pla)
	{
	//	printf("la distancia al pla es:%f",p);
		return(pl);
	}
	if (esfera)
		return(sp);
	return (0);
}
