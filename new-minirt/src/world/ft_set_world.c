#include "world.h"

void	ft_set_world(t_ambient *amb, t_world *world)
{
	world->camera = ft_build_camera(amb);
	world->projection = ft_build_plane_projection(world->camera);
}
