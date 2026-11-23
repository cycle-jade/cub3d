#ifndef EVENTS_H
# define EVENTS_H

# include <stdbool.h>

# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100

# define KEY_UP     65362
# define KEY_DOWN   65364
# define KEY_LEFT   65361
# define KEY_RIGHT  65363

# define KEY_ESC    65307
# define KEY_F1     65470

typedef struct s_vec
{
	double	x;
	double	y;

}	t_vec;

typedef struct s_cam
{
	t_vec	pos;
	t_vec	vdir;
	t_vec	plane;
	double	mvm_s;
	double	rot_s;

}	t_cam;

typedef struct s_ctrls
{
	bool	show_fps;
	bool	mvm_north;
	bool	mvm_south;
	bool	mvm_east;
	bool	mvm_west;
	bool	pan_left;
	bool	pan_right;

}	t_ctrls;

#endif