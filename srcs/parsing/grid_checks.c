#include "../../Includes/cub3d.h"

bool	is_valid_tile(char c)
{
	if (c == FLOOR || c == WALL || c == EMPTY || c == NORTH || c == SOUTH
		|| c == EAST || c == WEST)
		return (true);
	return (false);
}

void	duplicate_spawn_check(t_cub *cub)
{
	if (!cub->map.pv.spawn_set)
		cub->map.pv.spawn_set = true;
	else
		error_exit(cub, "Error!\nMap format error - Multiple spawn points");
}

static void	check_edges(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->map.map_w)
	{
		if (cub->map.grid[0][i] == FLOOR || cub->map.grid[cub->map.map_h
			- 1][i] == FLOOR)
			error_exit(cub, "Error!\nMap format error - map not enclosed");
	}
	i = -1;
	while (++i < cub->map.map_h)
	{
		if (cub->map.grid[i][0] == FLOOR || cub->map.grid[i][cub->map.map_w
			- 1] == FLOOR)
			error_exit(cub, "Error!\nMap format error - map not enclosed");
	}
}

static void	check_floor_tile(t_cub *cub, char **grid, int x, int y)
{
	if (grid[x - 1][y] == EMPTY || grid[x + 1][y] == EMPTY || grid[x][y
		- 1] == EMPTY || grid[x][y + 1] == EMPTY || grid[x - 1][y - 1] == EMPTY
		|| grid[x - 1][y + 1] == EMPTY || grid[x + 1][y - 1] == EMPTY || grid[x
		+ 1][y + 1] == EMPTY)
		error_exit(cub, "Error!\nMap format error - map not enclosed");
}

void	validate_grid(t_cub *cub)
{
	int	i;
	int	j;

	check_edges(cub);
	i = 0;
	while (++i < cub->map.map_h - 1)
	{
		j = 0;
		while (++j < cub->map.map_w - 1)
		{
			if (cub->map.grid[i][j] == FLOOR)
				check_floor_tile(cub, cub->map.grid, i, j);
		}
	}
}
