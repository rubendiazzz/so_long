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

// Window title
# define TITLE "Guatemala"

// Movement
# define UP 'W'
# define LEFT 'A'
# define DOWN 'S'
# define RIGHT 'D'

typedef struct s_data
{
	mlx_t	*mlx;
	int		width;
	int		height;
	int		move_counter;
	int		collected;
	char	**map;
}			t_data;

#endif
