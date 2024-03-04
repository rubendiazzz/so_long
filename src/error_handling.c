/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:52:04 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 14:12:12 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(char *message, t_data *data)
{
	if (data->allocated_map)
		ft_free_matrix(data, (void **)data->map);
	free(data);
	printf("Error\n%s\n", message);
	exit(1);
}

void	ft_free_matrix(t_data *data, void **matrix)
{
	int	i;

	i = 0;
	while (i < data->rows && matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	ft_end_game(t_game *game)
{
	ft_free_matrix(game->data, (void **)game->map);
	free(game->textures);
	free(game->image);
	free(game->data);
	free(game);
}
