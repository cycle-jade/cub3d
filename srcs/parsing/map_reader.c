#include "../../Includes/cub3d.h"

// Reading of the map file into a buffer

static void	loop_read(t_cub *cub, char **map_buffer, int fd)
{
	char	buf[1024];
	int		rc;
	char	*temp;

	rc = 1;
	while (rc > 0)
	{
		rc = read(fd, buf, 1024);
		if (rc < 0)
			error_exit(cub, "Error!\nUnable to read file");
		else if (rc == 0)
			break ;
		buf[rc] = '\0';
		temp = ft_strjoin(*map_buffer, buf);
		free(*map_buffer);
		if (!temp)
			error_exit(cub, "Error!\nMemory allocation error");
		*map_buffer = temp;
	}
}

void	read_map(t_cub *cub, int fd, char **map_buffer)
{
	char	buf[1024];
	int		rc;

	rc = read(fd, buf, 1024);
	if (rc < 0)
		error_exit(cub, "Error!\nUnable to read file");
	else if (rc == 0)
		error_exit(cub, "Error!\nEmpty file");
	else
	{
		buf[rc] = '\0';
		*map_buffer = ft_strdup(buf);
		if (!*map_buffer)
			error_exit(cub, "Error!\nMemory allocation error");
		loop_read(cub, map_buffer, fd);
	}
}

// breaking up the buffer into lines

static char	*get_line(char **str, const char end)
{
	char	*line;
	char	*next;

	next = ft_strchr(*str, end);
	if (!next)
	{
		line = ft_strdup(*str);
		*str += ft_strlen(*str);
		return (line);
	}
	line = ft_substr(*str, 0, next - *str);
	*str = next + 1;
	return (line);
}

void	carve_lines(t_cub *cub, char **map_buffer, t_list **lines)
{
	char	*line;

	while (**map_buffer)
	{
		line = get_line(map_buffer, '\n');
		if (!line)
		{
			ft_lstclear(lines, free);
			error_exit(cub, "Error!\nMemory allocation error");
		}
		if (ft_strlen(line) == 0 && !cub->map.pv.map_started)
		{
			free(line);
			continue ;
		}
		if (!cub->map.pv.map_started)
			check_grid_started(cub, line);
		ft_lstadd_back(lines, ft_lstnew(line));
	}
}

// Call for map breakdown into lines

t_list	*get_map_lines(t_cub *cub, char *path)
{
	char		*map_buffer;
	char		*temp;
	t_list		*lines;
	int			fd;

	map_buffer = NULL;
	lines = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(cub, "Error!\nUnable to open file");
	read_map(cub, fd, &map_buffer);
	close(fd);
	temp = map_buffer;
	carve_lines(cub, &temp, &lines);
	free(map_buffer);
	return (lines);
}
