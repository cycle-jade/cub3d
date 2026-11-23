#include "../../Includes/cub3d.h"

int	texture_id(t_cub *cub)
{
	if (cub->raycast.side == 0)
	{
		if (cub->screen.ray_dir_x > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (cub->screen.ray_dir_y > 0)
			return (2);
		else
			return (3);
	}
}

void	draw_textured_stripe(t_cub *cub, int x)
{
	double	tex_step;
	double	tex_pos;
	int		y;
	int		color;

	tex_step = (double)TEX_SIZE / (double)cub->wall.line_height;
	tex_pos = (cub->wall.draw_start - cub->mlx_h / 2 + cub->wall.line_height
			/ 2) * tex_step;
	y = cub->wall.draw_start;
	while (y < cub->wall.draw_end)
	{
		cub->raycast.tex_y = ((int)tex_pos) & (TEX_SIZE - 1);
		tex_pos += tex_step;
		color = get_texture_pixel_color(&cub->w_tex[texture_id(cub)]->tex,
				(int)cub->raycast.tex_x, cub->raycast.tex_y);
		if (cub->raycast.side == 1)
			color = (color >> 1) & 0x7F7F7F;
		place_pixel(&cub->frame, x, y, color);
		y++;
	}
}
