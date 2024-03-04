/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:45:17 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 13:20:47 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief Main function, here we will execute all the other
 * functions. This is the most important function.
 *
 * @param ac
 * @param av
 * @return int
 */
int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, false);
	if (!data.mlx_ptr)
		return (MALLOC_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	// Loop
	mlx_loop(data.mlx_ptr);
	return (0);
}
