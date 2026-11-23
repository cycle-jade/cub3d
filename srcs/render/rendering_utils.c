#include "../../Includes/cub3d.h"

void	draw_stripe(t_cub *cub, int x)
{
	t_position	range;

	range.x = 0;
	range.y = cub->wall.draw_start - 1;
	draw_vertical_line(&cub->frame, x, range, cub->map.ccolour);
	range.x = cub->wall.draw_start;
	range.y = cub->wall.draw_end;
	draw_vertical_line(&cub->frame, x, range, cub->wall.color);
	range.x = cub->wall.draw_end + 1;
	range.y = cub->mlx_h - 1;
	draw_vertical_line(&cub->frame, x, range, cub->map.fcolour);
}

double	hit_point_calc(t_cub *cub)
{
	double	hit_point;

	if (cub->raycast.side == 0)
		hit_point = cub->cam.pos.y + cub->wall.perp_wall_dist
			* cub->screen.ray_dir_y;
	else
		hit_point = cub->cam.pos.x + cub->wall.perp_wall_dist
			* cub->screen.ray_dir_x;
	hit_point -= floor(hit_point);
	return (hit_point);
}

double	tex_x_calculation(t_cub *cub)
{
	double	tex_x;

	tex_x = (int)(hit_point_calc(cub) * (double)(TEX_SIZE));
	if (cub->raycast.side == 0 && cub->screen.ray_dir_x > 0)
		tex_x = TEX_SIZE - tex_x - 1;
	if (cub->raycast.side == 1 && cub->screen.ray_dir_y < 0)
		tex_x = TEX_SIZE - tex_x - 1;
	return (tex_x);
}

unsigned int	get_texture_pixel_color(t_img *texture, int tex_x, int tex_y)
{
	char	*pix;

	pix = texture->addr + (tex_y * texture->line_len + tex_x
			* (texture->bpp / 8));
	return (*(unsigned int *)pix);
}
