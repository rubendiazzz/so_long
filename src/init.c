/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:21:15 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 17:27:21 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_init_game(t_game *game, t_data *data)
{
	game->width = data->cols * PX_SIZE;
	game->height = data->rows * PX_SIZE;
	game->move_counter = 0;
	game->collected = 0;
	game->map = data->map;
	game->data = data;
	game->mlx = mlx_init(game->width, game->height, TITLE, false);
	if (!game->mlx)
		exit_handler("Mlx error", data);
	ft_get_textures(game);
	ft_get_images(game);
	draw_map(data, game, game->image);
	mlx_key_hook(game->mlx, &ft_action, game);
	mlx_loop(game->mlx);
}

void	ft_get_textures(t_game *game)
{
	game->textures->empty = mlx_new_texture(game->mlx, "textures/empty.png");
	game->textures->wall = mlx_new_texture(game->mlx, "textures/wall.png");
	game->textures->collectible = mlx_new_texture(game->mlx,
			"textures/collectible.png");
	game->textures->player = mlx_new_texture(game->mlx, "textures/player.png");
	game->textures->exit = mlx_new_texture(game->mlx, "textures/exit.png");
	game->textures->open_exit = mlx_new_texture(game->mlx,
			"textures/open_exit.png");
}

void	ft_get_images(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_images));
	if (!game->image)
		exit_handler("ft_calloc error", game->data);
	game->image->empty = mlx_texture_to_image(game->mlx, game->textures->empty);
	game->image->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	game->image->collectible = mlx_texture_to_image(game->mlx,
			game->textures->collectible);
	game->image->player = mlx_texture_to_image(game->mlx,
			game->textures->player);
	game->image->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
	game->image->open_exit = mlx_texture_to_image(game->mlx,
			game->textures->open_exit);
	mlx_delete_texture(game->textures->empty);
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->collectible);
	mlx_delete_texture(game->textures->player);
	mlx_delete_texture(game->textures->exit);
	mlx_delete_texture(game->textures->open_exit);
}
