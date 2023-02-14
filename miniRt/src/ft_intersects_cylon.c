
#include "../include/miniRT.h"
#include "../mlx/mlx.h"

static double   ft_a_value(t_object *obj, t_vector ray_dir)
{
	float		a;
	t_cylinder	*cylon;
	t_vector	cylon_normal;

	cylon = (t_cylinder *)ft_find_lst_obj(obj, cy);
	cylon_normal.x = cylon->x_normal;
        cylon_normal.y = cylon->y_normal;
        cylon_normal.z = cylon->z_normal;

	a = ft_dot_product_vect(cylon_normal,ray_dir);
       	
	return (a);
}

static double   ft_b_value(t_ambient *amb, t_object *obj)
{
	float		b;
	t_cylinder	*cylon;
	t_vector	cylon_normal;
	t_vector	cylon_center;
	t_cam		*cam;
	t_vector	cam_pos;

	cylon = (t_cylinder *)ft_find_lst_obj(obj, cy);
	cylon_normal.x = cylon->x_normal;
        cylon_normal.y = cylon->y_normal;
        cylon_normal.z = cylon->z_normal;

	cylon_center.x = cylon->x;
        cylon_center.y = cylon->y;
        cylon_center.z = cylon->z;
	
	cam = (t_cam *)ft_find_lst(amb, C);
        cam_pos.x = cam->x;
        cam_pos.y = cam->y;
        cam_pos.z = cam->z;

	b = ft_dot_product_vect(cylon_normal, ft_rest_vect(cam_pos,cylon_center));
	return (b);
}

static double   ft_c_value(t_ambient *amb, t_object *obj)
{

	float		c;
	float		cylon_height;
	t_cylinder	*cylon;
	t_vector	cylon_center;
	t_cam		*cam;
	t_vector	cam_pos;

	cylon = (t_cylinder *)ft_find_lst_obj(obj, cy);

	cylon_center.x = cylon->x;
        cylon_center.y = cylon->y;
        cylon_center.z = cylon->z;
	
	cylon_height = cylon->height;

	cam = (t_cam *)ft_find_lst(amb, C);
        cam_pos.x = cam->x;
        cam_pos.y = cam->y;
        cam_pos.z = cam->z;

  	 c = (cam_pos.x - cylon_center.x) * (cam_pos.x - cylon_center.x) + 
            (cam_pos.y - cylon_center.y) * (cam_pos.y - cylon_center.y) + 
            (cam_pos.z - cylon_center.z) * (cam_pos.z - cylon_center.z) - 
            cylon_height * cylon_height;
	return (c);
}
static double   ft_h_value(t_vector ray_dir, t_object *obj, t_ambient *amb, float t)
{

        float           h;
        t_cylinder      *cylon;
        t_vector        cylon_normal;
        t_vector        cylon_center;
        t_cam           *cam;
        t_vector        cam_pos;

        cylon = (t_cylinder *)ft_find_lst_obj(obj, cy);
        cylon_normal.x = cylon->x_normal;
        cylon_normal.y = cylon->y_normal;
        cylon_normal.z = cylon->z_normal;

        cylon_center.x = cylon->x;
        cylon_center.y = cylon->y;
        cylon_center.z = cylon->z;

        cam = (t_cam *)ft_find_lst(amb, C);
        cam_pos.x = cam->x; 
        cam_pos.y = cam->y; 
        cam_pos.z = cam->z;

        h = (cam_pos.x + t * ray_dir.x - cylon_center.x) * cylon_normal.x +
            (cam_pos.y + t * ray_dir.y - cylon_center.y) * cylon_normal.y +
            (cam_pos.z + t * ray_dir.z - cylon_center.z) * cylon_normal.z;
        return (h);
}

// Funció per calcular la intersecció d'un raig amb un cilindre
int	ft_intersect_cylon(t_ambient *amb, t_object *obj, t_vector ray_dir, double *t)
{
	double  scalar_a;
	double  scalar_b;
	double  scalar_c;
	double	scalar_h;
	float	k;
	float	cylon_height;
	t_cylinder	*cylon;
	
	cylon = (t_cylinder *)ft_find_lst_obj(obj, cy);
	cylon_height = cylon->height;
	
	scalar_a = ft_a_value(obj, ray_dir); 
	scalar_b = ft_b_value(amb, obj);
	scalar_c = ft_c_value(amb, obj);
	k = (-scalar_b + sqrt(scalar_b * scalar_b - scalar_a * scalar_c)) / scalar_a;
	scalar_h = ft_h_value(ray_dir, obj, amb, k);
	
	if (scalar_h < 0 || scalar_h > cylon_height)
		return (0);
	*t = k;
	return (1);
}
