#include "../Includes/cub3d.h"

void	textures_init(t_cub *cub)
{
	int	i;

	cub->w_tex = (t_tex **)malloc(sizeof(t_tex *) * 4);
	if (!cub->w_tex)
		return ;
	i = -1;
	while (++i < 4)
	{
		cub->w_tex[i] = (t_tex *)malloc(sizeof(t_tex));
		if (!cub->w_tex[i])
			error_exit(cub, "Error!\n Texture malloc error");
		cub->w_tex[i]->tex.img = mlx_xpm_file_to_image(cub->mlx,
				cub->map.tex_paths[i], &cub->w_tex[i]->w, &cub->w_tex[i]->h);
		if (!cub->w_tex[i]->tex.img)
			error_exit(cub, "Error!\n Texture failed to load");
		cub->w_tex[i]->tex.addr = mlx_get_data_addr(cub->w_tex[i]->tex.img,
				&cub->w_tex[i]->tex.bpp, &cub->w_tex[i]->tex.line_len,
				&cub->w_tex[i]->tex.endian);
	}
}

static void	init_mlx(t_cub *cub)
{
	cub->mlx_h = 1080;
	cub->mlx_w = 1920;
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, cub->mlx_w, cub->mlx_h, "Cube3D");
	cub->frame.img = mlx_new_image(cub->mlx, cub->mlx_w, cub->mlx_h);
	cub->frame.addr = mlx_get_data_addr(cub->frame.img,
			&cub->frame.bpp, &cub->frame.line_len, &cub->frame.endian);
}

static void	init_ctrls(t_cub *cub)
{
	cub->ctrls.mvm_north = false;
	cub->ctrls.mvm_west = false;
	cub->ctrls.mvm_east = false;
	cub->ctrls.mvm_south = false;
	cub->ctrls.pan_right = false;
	cub->ctrls.pan_left = false;
	cub->ctrls.show_fps = false;
}

static void	init_map_validation(t_cub *cub)
{
	cub->map.pv.north = false;
	cub->map.pv.south = false;
	cub->map.pv.east = false;
	cub->map.pv.west = false;
	cub->map.pv.floor = false;
	cub->map.pv.ceiling = false;
	cub->map.pv.map_started = false;
	cub->map.pv.spawn_set = false;
}

void	init(t_cub *cub, char *path)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->w_tex = NULL;
	cub->frame.img = NULL;
	cub->map.grid = NULL;
	cub->map.tex_paths = NULL;
	init_mlx(cub);
	init_ctrls(cub);
	init_map_validation(cub);
	config_map(cub, path);
	textures_init(cub);
	fps(0);
}
