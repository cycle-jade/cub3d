#include "../../Includes/cub3d.h"

int	get_map_width(t_list *lines)
{
	int		max_w;
	int		line_w;
	t_list	*temp;

	max_w = 0;
	temp = lines;
	while (temp)
	{
		line_w = ft_strlen((char *)temp->content);
		if (line_w > max_w)
			max_w = line_w;
		temp = temp->next;
	}
	return (max_w);
}

void	set_nxt_grid_line(t_cub *cub, t_list **lines, int y)
{
	int		x;
	char	*line;

	x = 0;
	line = (char *)(*lines)->content;
	while (*line)
	{
		if (is_valid_tile(line[0]))
			cub->map.grid[y][x] = line[0];
		else
		{
			ft_lstclear(lines, free);
			error_exit(cub, "Error!\nMap format invalid - invalid map char");
		}
		line++;
		x++;
	}
	while (x < cub->map.map_w)
	{
		if (x < cub->map.map_w)
			cub->map.grid[y][x] = ' ';
		x++;
	}
	cub->map.grid[y][x] = '\0';
}

static void	config_spawn(t_cub *cub, int spawn_x, int spawn_y, int dir)
{
	cub->cam.pos.x = (double)spawn_x + 0.5;
	cub->cam.pos.y = (double)spawn_y + 0.5;
	if (dir == NORTH || dir == SOUTH)
		cub->cam.vdir.x = 0.0;
	if (dir == EAST || dir == WEST)
		cub->cam.vdir.y = 0.0;
	if (dir == NORTH)
		cub->cam.vdir.y = -1.0;
	if (dir == SOUTH)
		cub->cam.vdir.y = 1.0;
	if (dir == EAST)
		cub->cam.vdir.x = 1.0;
	if (dir == WEST)
		cub->cam.vdir.x = -1.0;
	cub->cam.plane.x = -cub->cam.vdir.y * 0.66;
	cub->cam.plane.y = cub->cam.vdir.x * 0.66;
	cub->cam.mvm_s = 0.133;
	cub->cam.rot_s = 0.066;
}

void	set_player_spawn(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->map.map_h)
	{
		j = -1;
		while (++j < cub->map.map_w)
		{
			if (cub->map.grid[i][j] == NORTH)
				config_spawn(cub, j, i, NORTH);
			else if (cub->map.grid[i][j] == SOUTH)
				config_spawn(cub, j, i, SOUTH);
			else if (cub->map.grid[i][j] == EAST)
				config_spawn(cub, j, i, EAST);
			else if (cub->map.grid[i][j] == WEST)
				config_spawn(cub, j, i, WEST);
			else
				continue ;
			cub->map.grid[i][j] = FLOOR;
			duplicate_spawn_check(cub);
		}
	}
	if (!cub->map.pv.spawn_set)
		error_exit(cub, "Error!\nMap format invalid - No spawn point");
}
