#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx_mac/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 800
#define TITLE "So Long"

typedef struct s_map {
	int		width; // Map width
	int		height; // Map height
	char	**map; // Map content
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_game;

#endif
