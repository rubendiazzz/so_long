#include "../inc/so_long.h"

void	draw_floor(t_data *data, t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '\n')
				mlx_image_to_window(game->mlx, image->empty, x * PX_SIZE, y
					* PX_SIZE);
			if (data->map[y][x] == WALL)
				mlx_image_to_window(game->mlx, image->wall, x * PX_SIZE, y
					* PX_SIZE);
			if (data->map[y][x] == EXIT)
			{
				mlx_image_to_window(game->mlx, image->open_exit, x * PX_SIZE, y
					* PX_SIZE);
				mlx_image_to_window(game->mlx, image->exit, x * PX_SIZE, y
					* PX_SIZE);
			}
			x++;
		}
	}
}

void	draw_map(t_data *data, t_game *game, t_images *image)
{
	int x;
	int y;

	draw_floor(data, game, image);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == COLLECTIBLE)
				mlx_image_to_window(game->mlx, image->collectible, x * PX_SIZE,
					y * PX_SIZE);
			if (data->map[y][x] == PLAYER)
				mlx_image_to_window(game->mlx, image->player, x * PX_SIZE, y
					* PX_SIZE);
			x++;
		}
		y++;
	}
}