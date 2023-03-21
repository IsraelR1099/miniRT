#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"
#include "../maths/maths.h"
#include "../world/world.h"

static double	ft_a_value(t_ray *ray_dir)
{
	return (ft_dot_product_vect(ray_dir->direction, ray_dir->direction));
}

static double	ft_b_value(t_object *obj, t_ray *ray_dir)
{
	t_sphere	*sphere;
	t_vector3d	sphere_pos;
	t_vector3d	res_cam_sphere;
	t_vector3d	cam_pos;

	cam_pos.x = ray_dir->origin.x;
	cam_pos.y = ray_dir->origin.y;
	cam_pos.z = ray_dir->origin.z;
	sphere = (t_sphere *)ft_find_lst_obj(obj, sp);
	sphere_pos.x = sphere->x;
	sphere_pos.y = sphere->y;
	sphere_pos.z = sphere->z;
	res_cam_sphere = ft_rest_vect(cam_pos, sphere_pos);
	if (ft_dot_product_vect(ray_dir->direction, res_cam_sphere) < 0)
		return(0);
	return (2 * ft_dot_product_vect(ray_dir->direction, res_cam_sphere));
}

static double	ft_c_value(t_ray *ray_dir, t_object *obj)
{
	t_vector3d	res_cam_sph;
	t_vector3d	cam_pos;
	t_vector3d	sphere_pos;
	t_sphere	*sphere;

	cam_pos.x = ray_dir->origin.x;
	cam_pos.y = ray_dir->origin.y;
	cam_pos.z = ray_dir->origin.z;
	sphere = (t_sphere *)ft_find_lst_obj(obj, sp);
	sphere_pos.x = sphere->x;
	sphere_pos.y = sphere->y;
	sphere_pos.z = sphere->z;
	res_cam_sph = ft_rest_vect(cam_pos, sphere_pos);
	return (ft_dot_product_vect(res_cam_sph, res_cam_sph) - ((sphere->diameter / 2) * (sphere->diameter / 2)));	
}

static double	ft_calc_t(double scalar_a, double scalar_b, double scalar_c, double *t)
{
	double	temp;
	double	t1;
	double	t0;
	double	temp2;
	double	ret;

	ret = scalar_b * scalar_b - (4 * scalar_a * scalar_c);
	if (ret < 0.0)
		return (0);
	temp = scalar_b * scalar_b - (4 * scalar_a * scalar_c);
	t1 = (-scalar_b + sqrt(temp)) / (2 * scalar_a);
	t0 = (-scalar_b - sqrt(temp)) / (2 * scalar_a);
/*
	if (t0 < 0 && t1 < 0 )
		return (0);
	else if (t0 <= 0.0)
		t0 = t1;
	else if (t1 <= 0.0)
		t1 = t0;
	 *t = ft_min_double(t0, t1);
	return(1);
	*/

	if (t0 > t1) 
    	{
		temp2 = t0;
		t0 = t1;
		t1 = temp2;
		if (t0 < 0.0) 
		{
			t0 = t1;
		}
		if (t0 < 0.0)
		{
			return (0);
		}
	}
		*t = (t0);
    	//*t = fabs(t0);
    	return (1);
		

}

int	ft_inter_sphere(t_object *obj, t_ray *ray_dir, double *t)
{
	double	scalar_a;
	double	scalar_b;
	double	scalar_c;
	
	scalar_a = ft_a_value(ray_dir);
	scalar_b = ft_b_value(obj, ray_dir);
	scalar_c = ft_c_value(ray_dir, obj);
	return(ft_calc_t(scalar_a, scalar_b, scalar_c, t));
}
