/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:45:17 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 14:05:36 by rdiaz-fr         ###   ########.fr       */
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
	// TODO: Handle malloc error with exit handling function
	// TODO: Read map function
	// TODO: Allocate game
	// TODO: Malloc check
	// TODO: Init game
	mlx_terminate(game->mlx);
	// End game
	return (0);
}
