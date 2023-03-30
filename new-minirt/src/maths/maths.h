/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:14:44 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 11:00:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <math.h>
# include "../parser/parser.h"

# define PI 3.141592653589
# define kEpsilon 0.0001

typedef struct s_point2d
{
	double	x;
	double	y;
}	t_point2d;

typedef struct s_vector3d
{
	double	x;
	double	y;
	double	z;
}	t_vector3d;

typedef struct s_point3d
{
	double	x;
	double	y;
	double	z;
}	t_point3d;

typedef struct s_ray
{
	t_point3d	origin;
	t_vector3d	direction;
}	t_ray;

double		ft_dot_product_vect(t_vector3d vector_left, t_vector3d vector_right);
t_vector3d	ft_vectorial_product(t_vector3d vector_left, t_vector3d vector_right);
t_vector3d	ft_rest_vect(t_vector3d origin, t_vector3d obj);
t_vector3d	ft_sum_vect(t_vector3d first, t_vector3d second);
t_vector3d	ft_product_vect_scalar(t_vector3d vector, double scalar);
t_vector3d	ft_normalize(t_vector3d ray_dir);
void		ft_normalize_vect_points(t_cylinder *cylon);
double		length(t_vector3d a);
double	ft_min_double(double x, double y);

#endif
