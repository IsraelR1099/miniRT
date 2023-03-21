
#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"
#include "../maths/maths.h"
#include "../world/world.h"

int	ft_intersects(t_object *obj, t_ray *ray_dir)
{
	double		t;
	int		esfera;

	t = 0.0;	
	esfera = ft_inter_sphere(obj, ray_dir, &t);
	return (esfera);
}
