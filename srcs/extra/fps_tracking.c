#include "../../Includes/cub3d.h"

char	*fps(int *frames)
{
	static char		*fps = NULL;
	static double	prev_time = 0;
	double			now;
	double			session;

	if (prev_time == 0)
		prev_time = get_time_now();
	now = get_time_now();
	session = now - prev_time;
	if (session >= 1000.0)
	{
		if (fps)
			free(fps);
		fps = ft_itoa((int)(*frames * 1000.0 / session));
		*frames = 0;
		prev_time = now;
	}
	return (fps);
}
