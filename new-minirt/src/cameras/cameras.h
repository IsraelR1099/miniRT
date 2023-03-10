/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:56:12 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 11:45:28 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERAS_H
# define CAMERAS_H

# include "../parser/parser.h"
# include "../maths/maths.h"

typedef struct s_cameras
{
	t_point3d	eye;
	t_point3d	lookat;
	t_vector3d	right;
	t_vector3d	up;
	t_vector3d	forward;
	t_vector3d	center;
	float		dis;
}	t_cameras;
typedef struct	s_projection
{
	float		hsize;
	float		vsize;
	float		hpixel;
	float		vpixel;
	t_point3d	origin;
}	t_projection;

t_cameras		*ft_build_camera(t_ambient *amb);
t_vector3d		ft_upvector(t_cameras camera);
t_vector3d		ft_rightaxis(t_vector3d forward);
t_vector3d		ft_forwardvector(t_cameras camera);
t_projection	*ft_build_plane_projection(t_cameras *camera, t_projection *planeproj);
//Utils
t_ambient	*ft_find_amb(t_ambient *amb, int type);

#endif
