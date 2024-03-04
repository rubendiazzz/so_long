/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:28:47 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 17:37:59 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Main libraries
# include "mlx/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// Error definitions
# define MALLOC_ERROR 1

// Map
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define EMPTY '0'
# define COLLECTIBLE 'C'

// Window size
# define WIDTH 800
# define HEIGHT 600

// Window title 💀
# define TITLE "Turkish Arruspuchuchu"
// PX SIZE
# define PX_SIZE 64

typedef struct s_img
{
	const uint32_t		width;
	const uint32_t		height;
	uint8_t				*pixels;
}						t_img;

typedef struct s_data
{
	char				**map;
	int					rows;
	int					cols;
	int					p_position[2];
	int					collectibles;
	int					players;
	int					exits;
	int					found;
	bool				allocated_map;
}						t_data;

typedef struct s_textures
{
	mlx_texture_t		*empty;
	mlx_texture_t		*wall;
	mlx_texture_t		*collectible;
	mlx_texture_t		*player;
	mlx_texture_t		*exit;
	mlx_texture_t		*open_exit;
}						t_textures;

typedef struct s_images
{
	mlx_image_t			*empty;
	mlx_image_t			*wall;
	mlx_image_t			*collectible;
	mlx_image_t			*player;
	mlx_image_t			*exit;
	mlx_image_t			*open_exit;
}						t_images;

typedef struct s_game
{
	mlx_t				*mlx;
	int					width;
	int					height;
	int					move_counter;
	int					collected;
	char				**map;
	struct s_textures	*textures;
	struct s_images		*image;
	struct s_data		*data;
}						t_game;

// Errors
void					exit_error(char *message, t_data *data);
void					ft_free_matrix(t_data *data, void **matrix);
void					ft_end_game(t_game *game);

// Key hooks
void					ft_action(mlx_key_data_t keydata, void *param);
void					ft_move_up(t_game *game);
void					ft_move_down(t_game *game);
void					ft_move_left(t_game *game);
void					ft_move_right(t_game *game);

// Read Map
void					read_map(char *map_path, t_data *data);

// Game
// Init game
t_game					*ft_init_game(t_data *data);
// End game
void					end_game(t_game *game, t_data *data);

#endif
