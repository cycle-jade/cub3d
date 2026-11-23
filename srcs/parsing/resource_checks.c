#include "../../Includes/cub3d.h"

bool	is_rgb_format_valid(char *line)
{
	int	sections;

	sections = 1;
	while (*line)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line == ',')
		{
			sections++;
			line++;
		}
		else
			break ;
	}
	if (sections != 3)
		return (false);
	return (true);
}

void	check_resource_path(t_cub *cub, int iden)
{
	int		fd;

	if (iden < 0 || iden > 3)
		return ;
	fd = open(cub->map.tex_paths[iden], O_RDONLY);
	if (fd < 0)
		error_exit(cub, "Error!\nUnable to open texture file");
	close(fd);
}

bool	resources_complete(t_par_validation pv)
{
	if (pv.north && pv.south && pv.east && pv.west
		&& pv.floor && pv.ceiling)
		return (true);
	return (false);
}

void	check_grid_started(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == WALL)
		cub->map.pv.map_started = true;
}
