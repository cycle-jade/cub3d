#ifndef CUB3D_H
# define CUB3D_H

# include "../Libs/minilibx-linux/mlx.h"
# include "../Libs/libft/libft.h"
# include "events.h"
# include "map.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# define TEX_SIZE 64 

// RAYCASTING

typedef struct s_screen_proj
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

}	t_screen_proj;

typedef struct s_raycasting
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	double	hit_point;
	double	tex_x;
	double	tex_y;
	int		side;

}	t_raycasting;

typedef struct s_wall_proj
{
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;

}	t_wall_proj;

// IMAGE STRUCTURES

typedef struct s_position
{
	int	x;
	int	y;

}	t_position;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_position	pos;

}	t_img;

typedef struct s_tex
{
	t_img	tex;
	int		w;
	int		h;

}	t_tex;

// MAIN MLX STRUCTURE
typedef struct s_cub
{
	int				mlx_w;
	int				mlx_h;
	void			*mlx;
	void			*win;
	t_img			frame;
	t_tex			**w_tex;
	t_cam			cam;
	t_map			map;
	t_ctrls			ctrls;
	t_screen_proj	screen;
	t_raycasting	raycast;
	t_wall_proj		wall;

}	t_cub;

// ----- init -----

void			config_map(t_cub *cub, char *path);
void			init(t_cub *cub, char *path);

// ----- events -----

int				handle_keypress(int keycode, t_cub *cub);
int				handle_keyrelease(int keycode, t_cub *cub);

// ----- utils -----

double			get_time_now(void);
void			toggle_fps(t_cub *cub);
char			*fps(int *frames);
int				set_colour(t_colour c);
void			place_pixel(t_img *img, int x, int y, int colour);

// ----- parsing map file -----

void			carve_lines(t_cub *cub, char **map_buffer, t_list **lines);
void			read_map(t_cub *cub, int fd, char **map_buffer);
t_list			*get_map_lines(t_cub *cub, char *path);

// ----- parsing gird data -----

void			set_player_spawn(t_cub *cub);
int				get_map_width(t_list *lines);
void			set_nxt_grid_line(t_cub *cub, t_list **lines, int y);

// ----- parsing resource data-----

void			set_data(t_cub *cub, int iden, char *line);
int				get_identifier(t_cub *cub, t_list **lines);

// ----- parsing checks -----

bool			resources_complete(t_par_validation pv);
void			check_grid_started(t_cub *cub, char *line);
bool			is_valid_tile(char c);
bool			is_rgb_format_valid(char *line);
void			duplicate_spawn_check(t_cub *cub);
void			validate_grid(t_cub *cub);

// ----- exits -----

int				close_win(void *param);
void			clean_exit(t_cub *cub, int status);
void			error_exit(t_cub *cub, char *msg);

// ----- render -----

void			draw_textured_stripe(t_cub *cub, int x);
double			hit_point_calc(t_cub *cub);
double			tex_x_calculation(t_cub *cub);
void			raycasting(t_cub *cub);
void			draw_vertical_line(t_img *img,
					int x, t_position range, int color);
void			cast_ray(t_cub *cub, int x);
void			rays(t_cub *cub);
void			rotate_right(t_cub *cub);
void			rotate_left(t_cub *cub);
void			update_player_position(t_cub *cub);
void			draw_stripe(t_cub *cub, int x);
void			delta(t_cub *cub);
int				is_walkable_with_radius(t_cub *cub, double x, double y);
void			mvm_north_south(t_cub *cub, double *nx, double *ny);
void			mvm_east_west(t_cub *cub, double *nx, double *ny);
void			rotate_left(t_cub *cub);
void			rotate_right(t_cub *cub);
unsigned int	get_texture_pixel_color(t_img *texture, int tex_x, int tex_y);

#endif