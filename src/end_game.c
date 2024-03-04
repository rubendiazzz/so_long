/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:18:44 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 17:19:01 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	end_game(t_game *game, t_data *data)
{
	mlx_terminate(game->mlx);
	free(data->map);
	free(data);
	free(game);
	exit(0);
}
