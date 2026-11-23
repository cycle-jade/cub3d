#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <stdbool.h>

# define FLOOR '0'
# define WALL '1'
# define EMPTY ' '
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

// tex paths: NO - SO - EA - WE

typedef struct s_colour
{
	int	a;
	int	r;
	int	g;
	int	b;

}	t_colour;

typedef struct s_par_validation
{
	bool	north;
	bool	south;
	bool	east;
	bool	west;
	bool	floor;
	bool	ceiling;
	bool	map_started;
	bool	spawn_set;

}	t_par_validation;

typedef struct s_map
{
	char				**grid;
	int					map_h;
	int					map_w;
	int					fcolour;
	int					ccolour;
	char				**tex_paths;
	t_par_validation	pv;

}	t_map;

#endif