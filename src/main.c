/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:45:17 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 17:28:51 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Exactly 1 map should be passed as argument"));
	data = malloc(sizeof(t_data));
	if (!data)
		exit_error("Malloc error", data);
	ft_read_map(data, argv);
	game = malloc(sizeof(t_game));
	if (!game)
		exit_error("Malloc error", data);
	ft_init_game(game, data);
	mlx_terminate(game->mlx);
	ft_end_game(game);
	return (0);
}
