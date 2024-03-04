/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:52:36 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 14:16:34 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_action(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_RELEASE && (keydata.key == MLX_KEY_W
			|| keydata.key == MLX_KEY_UP))
		ft_move_up(game);
	if (keydata.action == MLX_RELEASE && (keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_DOWN))
		ft_move_down(game);
	if (keydata.action == MLX_RELEASE && (keydata.key == MLX_KEY_A
			|| keydata.key == MLX_KEY_LEFT))
		ft_move_left(game);
	if (keydata.action == MLX_RELEASE && (keydata.key == MLX_KEY_D
			|| keydata.key == MLX_KEY_RIGHT))
		ft_move_right(game);
	if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	ft_collect(game);
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->image->player->instances->y / PX_SIZE
		- 1][game->image->player->instances->x / PX_SIZE] != WALL)
	{
		game->image->player->instances->y -= PX_SIZE;
		game->move_counter++;
		ft_printf("MOVES: %d\n", game->move_counter);
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->image->player->instances->y / PX_SIZE
		+ 1][game->image->player->instances->x / PX_SIZE] != WALL)
	{
		game->image->player->instances->y += PX_SIZE;
		game->move_counter++;
		ft_printf("MOVES: %d\n", game->move_counter);
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->image->player->instances->y
		/ PX_SIZE][game->image->player->instances->x / PX_SIZE - 1] != WALL)
	{
		game->image->player->instances->x -= PX_SIZE;
		game->move_counter++;
		ft_printf("MOVES: %d\n", game->move_counter);
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->image->player->instances->y
		/ PX_SIZE][game->image->player->instances->x / PX_SIZE + 1] != WALL)
	{
		game->image->player->instances->x += PX_SIZE;
		game->move_counter++;
		ft_printf("MOVES: %d\n", game->move_counter);
	}
}