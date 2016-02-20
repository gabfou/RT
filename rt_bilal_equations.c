inline t_vect3d	inter_cylinder_point(t_list *cylinder, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	t_vect3d	ret;

	a = dot_product(ray.direct, ray.direct) - ( dot_product(ray.direct, cylinder->orient) *  dot_product(ray.direct, cylinder->orient));
	b = dot_product(ray.direct, new_vector(cylinder->center, ray.origin)) - (dot_product(ray.direct, cylinder->orient) * dot_product(new_vector(cylinder->center, ray.origin), cylinder->orient));
	b = 2.0 * b;
	c = dot_product(new_vector(cylinder->center, ray.origin), new_vector(cylinder->center, ray.origin)) - (dot_product(new_vector(cylinder->center, ray.origin), cylinder->orient) * dot_product(new_vector(cylinder->center, ray.origin), cylinder->orient));
	c = c - cylinder->radiangle * cylinder->radiangle;

	delta = b * b - ( 4.0 * a * c);
	ret.t = ( ((-b + sqrt(delta)) / (2 * a)) > ((-b - sqrt(delta)) / (2.0 * a)))
	? ((-b - sqrt(delta)) / (2.0 * a)) : ((-b + sqrt(delta)) / (2.0 * a));
	ret.inter =  (!(delta < 0 ));
	ret.x = ret.t * ray.direct.x + ray.origin.x;
	ret.y = ret.t * ray.direct.y + ray.origin.y;
	ret.z = ret.t * ray.direct.z + ray.origin.z;
	return (ret);
}

inline t_vect3d	inter_cone_point(t_list *cylinder, t_ray ray)
{
	t_vect3d	ret;
	double		a;
	double		b;
	double		c;
	double		delta;

	a = dot_product(ray.direct, ray.direct) - (1.0 + tan(cylinder->radiangle) * tan(cylinder->radiangle)) * ( dot_product(ray.direct, cylinder->orient) *  dot_product(ray.direct, cylinder->orient));
	b = dot_product(ray.direct, vector_sub(ray.origin, cylinder->center)) - (1.0 + tan(cylinder->radiangle) * tan(cylinder->radiangle)) * (dot_product(ray.direct, cylinder->orient) * dot_product(vector_sub(ray.origin, cylinder->center), cylinder->orient));
	b = 2 * b;
	c = dot_product(new_vector(cylinder->center, ray.origin), new_vector(cylinder->center, ray.origin)) - (1.0 + tan(cylinder->radiangle) * tan(cylinder->radiangle)) * (dot_product(vector_sub(ray.origin, cylinder->center), cylinder->orient) * dot_product(vector_sub(ray.origin, cylinder->center), cylinder->orient));


	delta = b * b - ( 4 * a * c);

	ret.t = ( ((-b + sqrt(delta)) / (2 * a)) > ((-b - sqrt(delta)) / (2.0 * a)))
	? ((-b - sqrt(delta)) / (2.0 * a)) : ((-b + sqrt(delta)) / (2.0 * a));
	ret.inter = (!(delta < 0));
	ret.x = ret.t * ray.direct.x + ray.origin.x;
	ret.y = ret.t * ray.direct.y + ray.origin.y;
	ret.z = ret.t * ray.direct.z + ray.origin.z;
	return (ret);
}

inline t_vect3d		vector_proj_vector(t_vect3d vector1, t_vect3d vector2) // project vector 1 in vector 2
{
	t_vect3d	ret;

	ret = vector_mult(vector2, dot_product(vector1, vector2) / dot_product(vector2, vector2));
	return (ret);	
}

inline unsigned long	color_at_c(t_env *e, t_vect3d inter, t_ray ray, t_vect3d *normale)
{
	unsigned long	color;
	double			r;
	double			m;
	t_vect3d		normal;
	t_vect3d	light_prim;

	m = dot_product(ray.direct, e->list->orient) * inter.t + dot_product(vector_sub(ray.origin, e->list->center), e->list->orient);
	normal = normalizator((vector_sub((vector_sub(vector_mult(ray.direct, inter.t), e->list->center)), (vector_mult(e->list->orient, m)))) );
	*normale = normal;
	light_prim = vector_sub(inter, e->lights->center);
	light_prim = normalizator(light_prim);
	r = dot_product((light_prim), (normal));
	r = acos(r) * (40.7436609389);
	r *= 0.9;
	color = ((int)r << 0 | (int)r << 8 | (int)r << 16 | (0 << 24));
	return (color);
}

inline unsigned long	color_at_cone(t_env *e, t_vect3d inter, t_vect3d *normale)
{
	unsigned long	color;
	double			r;
	t_vect3d		normal;
	t_vect3d	light_prim;

	normal = vector_sub(vector_proj_vector(normalizator(vector_sub(e->list->center, inter)), e->list->orient), normalizator(vector_sub(e->list->center, inter)));
	normal = normalizator(normal);
	*normale = normal;
	light_prim = vector_sub(inter, e->lights->center);
	light_prim = normalizator(light_prim);
	r = dot_product((light_prim), (normal));
	r = acos(r) * (40.7436609389);
	r *= 0.9;
	color = ((int)r << 0 | (int)r << 8 | (int)r << 16 | (0 << 24));
	return (color);
}