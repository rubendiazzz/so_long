#include "../inc/so_long.h"

int main(int ac, char **av)
{
	t_game	*win;
	t_game	*connection;

	connection = mlx_init();
	win = mlx_new_window();

	mlx_loop(connection);
}
