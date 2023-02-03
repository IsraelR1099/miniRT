/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:52:18 by msoler-e          #+#    #+#             */
/*   Updated: 2023/02/03 12:19:24 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

p_ray	set_prim_ray ( t_ambient *amb)
{
	p_ray prim_ray;

	t_ambient *ambsearch;
	t_cam	  *cam;
	
	ambsearch = amb;
	ambsearch = s_lst ( ambsearch, C );
   	cam = (t_cam *)ambsearch ;

	prim_ray.t=0;
	return(prim_ray);
}
