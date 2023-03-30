#include "maths.h"

double length(t_vector3d a)
{
  return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

t_vector3d        ft_normalize(t_vector3d ray_dir)
{
        double   len;

        len = length(ray_dir);
        ray_dir.x /= len;
        ray_dir.y /= len;
        ray_dir.z /= len;
        return (ray_dir);
}

void	ft_normalize_vect_points(t_cylinder *cylon)
{
	t_vector3d	temp;

	temp.x = cylon->x_normal;
	temp.y = cylon->y_normal;
	temp.z = cylon->z_normal;
	temp = ft_normalize(temp);
	
	cylon->x_normal = temp.x; 
	cylon->y_normal = temp.y;
	cylon->z_normal = temp.z;
}
