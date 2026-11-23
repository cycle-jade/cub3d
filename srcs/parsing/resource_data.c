#include "../../Includes/cub3d.h"

static t_colour	get_colour(char *line)
{
	int			i;
	t_colour	colour;

	i = 0;
	colour.a = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	colour.r = ft_atoi(&line[i]) % 256;
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == ',')
		i++;
	colour.g = ft_atoi(&line[i]) % 256;
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == ',')
		i++;
	colour.b = ft_atoi(&line[i]) % 256;
	return (colour);
}

int	get_identifier(t_cub *cub, t_list **lines)
{
	char	*line;

	line = (char *)(*lines)->content;
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0 && !cub->map.pv.north)
		return (cub->map.pv.north = true, 0);
	else if (ft_strncmp(line, "SO ", 3) == 0 && !cub->map.pv.south)
		return (cub->map.pv.south = true, 1);
	else if (ft_strncmp(line, "EA ", 3) == 0 && !cub->map.pv.east)
		return (cub->map.pv.east = true, 2);
	else if (ft_strncmp(line, "WE ", 3) == 0 && !cub->map.pv.west)
		return (cub->map.pv.west = true, 3);
	else if (ft_strncmp(line, "F ", 2) == 0 && !cub->map.pv.floor)
		return (cub->map.pv.floor = true, 4);
	else if (ft_strncmp(line, "C ", 2) == 0 && !cub->map.pv.ceiling)
		return (cub->map.pv.ceiling = true, 5);
	else
	{
		ft_lstclear(lines, free);
		error_exit(cub,
			"Error!\nDuplicate or unknown resource identifier");
	}
	return (-1);
}

void	set_data(t_cub *cub, int iden, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	line += 2;
	while (*line == ' ' || *line == '\t')
		line++;
	if (iden == 0)
		cub->map.tex_paths[0] = ft_strdup(line);
	else if (iden == 1)
		cub->map.tex_paths[1] = ft_strdup(line);
	else if (iden == 2)
		cub->map.tex_paths[2] = ft_strdup(line);
	else if (iden == 3)
		cub->map.tex_paths[3] = ft_strdup(line);
	else if (iden == 4 || iden == 5)
	{
		if (is_rgb_format_valid(line) == false)
		{
			ft_lstclear(NULL, free);
			error_exit(cub, "Error!\nMap format invalid - invalid rgb format");
		}
		if (iden == 4)
			cub->map.fcolour = set_colour(get_colour(line));
		else if (iden == 5)
			cub->map.ccolour = set_colour(get_colour(line));
	}
}
