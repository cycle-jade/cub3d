#include "../Includes/cub3d.h"

void	draw_backgroud(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (cub->mlx_h / 2))
	{
		x = -1;
		while (++x < (cub->mlx_w))
			place_pixel(&cub->frame, x, y, cub->map.ccolour);
	}
	--y;
	while (++y < (cub->mlx_h))
	{
		x = -1;
		while (++x < (cub->mlx_w))
			place_pixel(&cub->frame, x, y, cub->map.fcolour);
	}
}

static int	update(t_cub *cub)
{
	static int	frames = 0;

	draw_backgroud(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->frame.img, 0, 0);
	frames++;
	if (cub->ctrls.show_fps)
		mlx_string_put(cub->mlx, cub->win, 10, 20, 0, fps(&frames));
	return (0);
}

static void	check_input(int argc, char **argv)
{
	int		len;
	char	*input;

	if (argc < 2)
	{
		printf("Error!\nNo file provided");
		exit(EXIT_FAILURE);
	}
	input = argv[1];
	len = ft_strlen(input);
	if (len < 5 || ft_strchr(input, '.') != ft_strrchr(input, '.'))
	{
		printf("Error!\nInvalid file");
		exit(EXIT_FAILURE);
	}
	if (input[len - 1] != 'b' || input[len - 2] != 'u'
		|| input[len - 3] != 'c' || input[len - 4] != '.')
	{
		printf("Error!\nInvalid file - not a .cub file");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	check_input(argc, argv);
	init(&cub, argv[1]);
	mlx_hook(cub.win, 2, 1L << 0, handle_keypress, &cub);
	mlx_hook(cub.win, 3, 1L << 1, handle_keyrelease, &cub);
	mlx_hook(cub.win, 17, 0, close_win, &cub);
	mlx_loop_hook(cub.mlx, update, &cub);
	mlx_loop(cub.mlx);
	(void)argc;
}
