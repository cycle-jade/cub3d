#include "../../Includes/cub3d.h"

void	draw_vertical_line(t_img *img, int x, t_position range, int color)
{
	int	y;

	y = range.x - 1;
	while (++y <= range.y)
		place_pixel(img, x, y, color);
}

void	rays(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < cub->mlx_w)
	{
		cast_ray(cub, x);
		x++;
	}
}

void	raycasting(t_cub *cub)
{
	rays(cub);
	update_player_position(cub);
}
