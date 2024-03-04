/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:45:17 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 17:08:20 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_game	*game;

	if (ac != 2)
		return (printf("Exactly 1 map should be passed as an argument!"));
	data = malloc(sizeof(t_data));
	if (!data)
		exit_error("Error", data);
	// TODO: Read map function
	// TODO: Allocate game
	// TODO: Malloc check
	// TODO: Init game
	mlx_terminate(game->mlx);
	// End game
	return (0);
}
