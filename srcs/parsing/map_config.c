#include "../../Includes/cub3d.h"

static void	config_resources(t_cub *cub, t_list **lines)
{
	int	iden;

	while (*lines && !resources_complete(cub->map.pv))
	{
		iden = get_identifier(cub, lines);
		set_data(cub, iden, (char *)(*lines)->content);
		*lines = (*lines)->next;
	}
}

static void	config_grid(t_cub *cub, t_list **lines)
{
	int	i;

	i = -1;
	cub->map.map_h = ft_lstsize(*lines);
	if (cub->map.map_h == 0)
	{
		ft_lstclear(lines, free);
		error_exit(cub, "Error!\nMap format invalid - no map data found");
	}
	cub->map.map_w = get_map_width(*lines);
	cub->map.grid = malloc(sizeof(char *) * (cub->map.map_h + 1));
	cub->map.grid[cub->map.map_h] = NULL;
	if (!cub->map.grid)
	{
		ft_lstclear(lines, free);
		error_exit(cub, "Error!\nMemory allocation error");
	}
	while (++i < cub->map.map_h)
	{
		cub->map.grid[i] = malloc(sizeof(char) * cub->map.map_w + 1);
		set_nxt_grid_line(cub, lines, i);
		*lines = (*lines)->next;
	}
	set_player_spawn(cub);
}

void	config_map(t_cub *cub, char *path)
{
	t_list	*lines;
	t_list	*temp;

	lines = get_map_lines(cub, path);
	if (!lines)
		error_exit(cub, "Error!\nMap format invalid - no data found");
	temp = lines;
	cub->map.tex_paths = malloc(sizeof(char *) * 4);
	if (ft_lstsize(lines) < 6)
	{
		ft_lstclear(&lines, free);
		error_exit(cub, "Error!\nMap format invalid - insufficient data");
	}
	config_resources(cub, &temp);
	if (!resources_complete(cub->map.pv))
	{
		ft_lstclear(&lines, free);
		error_exit(cub, "Error!\nMap format invalid - missing texture/colour");
	}
	config_grid(cub, &temp);
	ft_lstclear(&lines, free);
	validate_grid(cub);
}
