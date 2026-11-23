#include "../../Includes/cub3d.h"

void	sidedist(t_cub *cub)
{
	if (cub->screen.ray_dir_x < 0)
	{
		cub->raycast.step_x = -1;
		cub->raycast.side_dist_x = (cub->cam.pos.x - cub->raycast.map_x)
			* cub->raycast.delta_dist_x;
	}
	else
	{
		cub->raycast.step_x = 1;
		cub->raycast.side_dist_x = (cub->raycast.map_x + 1.0 - cub->cam.pos.x)
			* cub->raycast.delta_dist_x;
	}
	if (cub->screen.ray_dir_y < 0)
	{
		cub->raycast.step_y = -1;
		cub->raycast.side_dist_y = (cub->cam.pos.y - cub->raycast.map_y)
			* cub->raycast.delta_dist_y;
	}
	else
	{
		cub->raycast.step_y = 1;
		cub->raycast.side_dist_y = (cub->raycast.map_y + 1.0 - cub->cam.pos.y)
			* cub->raycast.delta_dist_y;
	}
}

void	delta(t_cub *cub)
{
	if (cub->screen.ray_dir_x == 0)
		cub->raycast.delta_dist_x = 1e30;
	else
		cub->raycast.delta_dist_x = fabs(1.0 / cub->screen.ray_dir_x);
	if (cub->screen.ray_dir_y == 0)
		cub->raycast.delta_dist_y = 1e30;
	else
		cub->raycast.delta_dist_y = fabs(1.0 / cub->screen.ray_dir_y);
}

bool	check_wall_hit(t_cub *cub)
{
	if (cub->raycast.map_x < 0 || cub->raycast.map_x >= cub->map.map_w
		|| cub->raycast.map_y < 0 || cub->raycast.map_y >= cub->map.map_h)
	{
		cub->raycast.hit = 1;
		return (true);
	}
	if (cub->map.grid[cub->raycast.map_y][cub->raycast.map_x] == '1')
		cub->raycast.hit = 1;
	return (false);
}

void	dda(t_cub *cub)
{
	cub->raycast.hit = 0;
	while (cub->raycast.hit == 0)
	{
		if (cub->raycast.side_dist_x < cub->raycast.side_dist_y)
		{
			cub->raycast.side_dist_x += cub->raycast.delta_dist_x;
			cub->raycast.map_x += cub->raycast.step_x;
			cub->raycast.side = 0;
		}
		else
		{
			cub->raycast.side_dist_y += cub->raycast.delta_dist_y;
			cub->raycast.map_y += cub->raycast.step_y;
			cub->raycast.side = 1;
		}
		if (check_wall_hit(cub))
			break ;
	}
	cub->wall.perp_wall_dist = 0.0;
	if (cub->raycast.side == 0)
		cub->wall.perp_wall_dist = (cub->raycast.side_dist_x
				- cub->raycast.delta_dist_x);
	else
		cub->wall.perp_wall_dist = (cub->raycast.side_dist_y
				- cub->raycast.delta_dist_y);
}

void	cast_ray(t_cub *cub, int x)
{
	cub->screen.camera_x = 2 * x / (double)cub->mlx_w - 1;
	cub->screen.ray_dir_x = cub->cam.vdir.x + cub->cam.plane.x
		* cub->screen.camera_x;
	cub->screen.ray_dir_y = cub->cam.vdir.y + cub->cam.plane.y
		* cub->screen.camera_x;
	cub->raycast.map_x = (int)cub->cam.pos.x;
	cub->raycast.map_y = (int)cub->cam.pos.y;
	delta(cub);
	sidedist(cub);
	dda(cub);
	cub->raycast.tex_x = tex_x_calculation(cub);
	cub->wall.line_height = (int)(cub->mlx_h / cub->wall.perp_wall_dist);
	cub->wall.draw_start = -cub->wall.line_height / 2 + cub->mlx_h / 2;
	if (cub->wall.draw_start < 0)
		cub->wall.draw_start = 0;
	cub->wall.draw_end = cub->wall.line_height / 2 + cub->mlx_h / 2;
	if (cub->wall.draw_end >= cub->mlx_h)
		cub->wall.draw_end = cub->mlx_h - 1;
	draw_textured_stripe(cub, x);
}
