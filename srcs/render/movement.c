#include "../../Includes/cub3d.h"

void	rotate_right(t_cub *cub)
{
	double	old_vdir_x;
	double	old_plane_x;

	old_vdir_x = cub->cam.vdir.x;
	cub->cam.vdir.x = cub->cam.vdir.x * cos(-cub->cam.rot_s) - cub->cam.vdir.y
		* sin(-cub->cam.rot_s);
	cub->cam.vdir.y = old_vdir_x * sin(-cub->cam.rot_s) + cub->cam.vdir.y
		* cos(-cub->cam.rot_s);
	old_plane_x = cub->cam.plane.x;
	cub->cam.plane.x = cub->cam.plane.x * cos(-cub->cam.rot_s)
		- cub->cam.plane.y * sin(-cub->cam.rot_s);
	cub->cam.plane.y = old_plane_x * sin(-cub->cam.rot_s) + cub->cam.plane.y
		* cos(-cub->cam.rot_s);
}

void	rotate_left(t_cub *cub)
{
	double	old_vdir_x;
	double	old_plane_x;

	old_vdir_x = cub->cam.vdir.x;
	cub->cam.vdir.x = cub->cam.vdir.x * cos(cub->cam.rot_s) - cub->cam.vdir.y
		* sin(cub->cam.rot_s);
	cub->cam.vdir.y = old_vdir_x * sin(cub->cam.rot_s) + cub->cam.vdir.y
		* cos(cub->cam.rot_s);
	old_plane_x = cub->cam.plane.x;
	cub->cam.plane.x = cub->cam.plane.x * cos(cub->cam.rot_s) - cub->cam.plane.y
		* sin(cub->cam.rot_s);
	cub->cam.plane.y = old_plane_x * sin(cub->cam.rot_s) + cub->cam.plane.y
		* cos(cub->cam.rot_s);
}

void	mvm_north_south(t_cub *cub, double *nx, double *ny)
{
	if (cub->ctrls.mvm_north)
	{
		*nx = (cub->cam.pos.x + cub->cam.vdir.x * cub->cam.mvm_s);
		*ny = (cub->cam.pos.y + cub->cam.vdir.y * cub->cam.mvm_s);
		if (is_walkable_with_radius(cub, *nx, cub->cam.pos.y))
			cub->cam.pos.x += cub->cam.vdir.x * cub->cam.mvm_s;
		if (is_walkable_with_radius(cub, cub->cam.pos.x, *ny))
			cub->cam.pos.y += cub->cam.vdir.y * cub->cam.mvm_s;
	}
	if (cub->ctrls.mvm_south)
	{
		*nx = (cub->cam.pos.x - cub->cam.vdir.x * cub->cam.mvm_s);
		*ny = (cub->cam.pos.y - cub->cam.vdir.y * cub->cam.mvm_s);
		if (is_walkable_with_radius(cub, *nx, cub->cam.pos.y))
			cub->cam.pos.x -= cub->cam.vdir.x * cub->cam.mvm_s;
		if (is_walkable_with_radius(cub, cub->cam.pos.x, *ny))
			cub->cam.pos.y -= cub->cam.vdir.y * cub->cam.mvm_s;
	}
}

void	mvm_east_west(t_cub *cub, double *nx, double *ny)
{
	if (cub->ctrls.mvm_east)
	{
		*nx = (cub->cam.pos.x + cub->cam.plane.x * cub->cam.mvm_s);
		*ny = (cub->cam.pos.y + cub->cam.plane.y * cub->cam.mvm_s);
		if (is_walkable_with_radius(cub, *nx, cub->cam.pos.y))
			cub->cam.pos.x += cub->cam.plane.x * cub->cam.mvm_s;
		if (is_walkable_with_radius(cub, cub->cam.pos.x, *ny))
			cub->cam.pos.y += cub->cam.plane.y * cub->cam.mvm_s;
	}
	if (cub->ctrls.mvm_west)
	{
		*nx = (cub->cam.pos.x - cub->cam.plane.x * cub->cam.mvm_s);
		*ny = (cub->cam.pos.y - cub->cam.plane.y * cub->cam.mvm_s);
		if (is_walkable_with_radius(cub, *nx, cub->cam.pos.y))
			cub->cam.pos.x -= cub->cam.plane.x * cub->cam.mvm_s;
		if (is_walkable_with_radius(cub, cub->cam.pos.x, *ny))
			cub->cam.pos.y -= cub->cam.plane.y * cub->cam.mvm_s;
	}
}
