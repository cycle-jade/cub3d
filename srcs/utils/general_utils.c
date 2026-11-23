#include "../../Includes/cub3d.h"

double	get_time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

void	toggle_fps(t_cub *cub)
{
	if (cub->ctrls.show_fps)
		cub->ctrls.show_fps = false;
	else
		cub->ctrls.show_fps = true;
}

void	place_pixel(t_img *img, int x, int y, int colour)
{
	char	*pix;

	pix = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pix = colour;
}

int	set_colour(t_colour c)
{
	return ((c.a << 24) | (c.r << 16) | (c.g << 8) | c.b);
}
