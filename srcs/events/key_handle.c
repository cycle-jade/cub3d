#include "../../Includes/cub3d.h"

void	handle_arrow_keypress(int keycode, t_cub *cub)
{
	if (keycode == KEY_UP)
		cub->ctrls.mvm_north = true;
	else if (keycode == KEY_DOWN)
		cub->ctrls.mvm_south = true;
	else if (keycode == KEY_LEFT)
		cub->ctrls.pan_left = true;
	else if (keycode == KEY_RIGHT)
		cub->ctrls.pan_right = true;
}

void	handle_arrow_keyrelease(int keycode, t_cub *cub)
{
	if (keycode == KEY_UP)
		cub->ctrls.mvm_north = false;
	else if (keycode == KEY_DOWN)
		cub->ctrls.mvm_south = false;
	else if (keycode == KEY_LEFT)
		cub->ctrls.pan_left = false;
	else if (keycode == KEY_RIGHT)
		cub->ctrls.pan_right = false;
}

int	handle_keypress(int keycode, t_cub *cub)
{
	if (keycode == KEY_ESC)
		clean_exit(cub, EXIT_SUCCESS);
	else if (keycode == KEY_F1)
		toggle_fps(cub);
	else if (keycode == KEY_W)
		cub->ctrls.mvm_north = true;
	else if (keycode == KEY_S)
		cub->ctrls.mvm_south = true;
	else if (keycode == KEY_A)
		cub->ctrls.mvm_west = true;
	else if (keycode == KEY_D)
		cub->ctrls.mvm_east = true;
	else if (keycode == KEY_LEFT)
		cub->ctrls.pan_left = true;
	else if (keycode == KEY_RIGHT)
		cub->ctrls.pan_right = true;
	handle_arrow_keypress(keycode, cub);
	return (0);
}

int	handle_keyrelease(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		cub->ctrls.mvm_north = false;
	else if (keycode == KEY_S)
		cub->ctrls.mvm_south = false;
	else if (keycode == KEY_A)
		cub->ctrls.mvm_west = false;
	else if (keycode == KEY_D)
		cub->ctrls.mvm_east = false;
	else if (keycode == KEY_LEFT)
		cub->ctrls.pan_left = false;
	else if (keycode == KEY_RIGHT)
		cub->ctrls.pan_right = false;
	handle_arrow_keyrelease(keycode, cub);
	return (0);
}
