#include "../../Includes/cub3d.h"

static int	is_walkable(t_cub *cub, double mx, double my)
{
	if (my < 0 || my >= cub->map.map_h || mx < 0 || mx >= cub->map.map_w)
		return (0);
	if (!cub->map.grid[(int)(my)])
		return (0);
	return (cub->map.grid[(int)my][(int)mx] == '0');
}

int	is_walkable_with_radius(t_cub *cub, double x, double y)
{
	if (!is_walkable(cub, x + 0.1, y))
		return (0);
	if (!is_walkable(cub, x - 0.1, y))
		return (0);
	if (!is_walkable(cub, x, y + 0.1))
		return (0);
	if (!is_walkable(cub, x, y - 0.1))
		return (0);
	return (1);
}

void	update_player_position(t_cub *cub)
{
	double	nx;
	double	ny;

	mvm_north_south(cub, &nx, &ny);
	mvm_east_west(cub, &nx, &ny);
	if (cub->ctrls.pan_right)
		rotate_left(cub);
	if (cub->ctrls.pan_left)
		rotate_right(cub);
}
