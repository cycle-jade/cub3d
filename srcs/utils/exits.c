#include "../../Includes/cub3d.h"

static void	free_map_config(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->map_h)
			free (map->grid[i++]);
		free (map->grid);
	}
	if (map->tex_paths)
	{
		i = 0;
		while (i < 4)
		{
			if (map->tex_paths[i])
			{
				free(map->tex_paths[i]);
				map->tex_paths[i] = NULL;
			}
			i++;
		}
		free(map->tex_paths);
	}
}

void	clean_exit(t_cub *cub, int status)
{
	int	i;

	i = -1;
	if (cub->w_tex)
	{
		while (++i < 4)
		{
			if (cub->w_tex[i])
			{
				mlx_destroy_image(cub->mlx, cub->w_tex[i]->tex.img);
				free(cub->w_tex[i]);
			}
		}
		free(cub->w_tex);
	}
	if (cub->frame.img)
		mlx_destroy_image(cub->mlx, cub->frame.img);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	if (cub->mlx)
		free(cub->mlx);
	free_map_config(&cub->map);
	exit(status);
}

void	error_exit(t_cub *cub, char *msg)
{
	perror(msg);
	clean_exit(cub, EXIT_FAILURE);
}

int	close_win(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	clean_exit(cub, 0);
	return (0);
}
