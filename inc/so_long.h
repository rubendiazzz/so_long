#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <unistd.h>

# PX_SIZE 32
# MALLOC_ERROR 1

# WALL '1'
# PLAYER 'P'
# EXIT 'E'
# PATH '0'

typedef struct	s_game {
	void		*mlx_con;
	void		*mlx_win;
	t_data		*data;
	t_texture	*texture;
}		t_game;

#endif
