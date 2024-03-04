/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:11:36 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 17:17:25 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Use GNL to get the map line by line
 * Check if the map is valid
 * Check if the map is rectangular
 * Check if the map has at least one player, one exit and one collectible
 * Check if the map has only valid characters
 * Check if the map has only one player
 * Check if the map has only one exit
 * Check if the map has at least one collectible
 * If the map is valid, store it in the data struct
 * If the map is invalid, free the data struct and exit the program
 * Free the map
 * Return
 */

#include "../inc/so_long.h"

void	read_map(char *map_path, t_data *data)
{
	int		fd;
	char	*line;
	int		ret;
	int		rows;
	int		cols;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_error("Error, you have to pass a map by argument.\n", data);
	ret = get_next_line(fd, &line);
	rows = 1;
	cols = ft_strlen(line);
	while (ret > 0)
	{
		if (cols != ft_strlen(line))
			exit_error("Error: Map is not rectangular", data);
		free(line);
		ret = get_next_line(fd, &line);
		rows++;
	}
	if (ret < 0)
		exit_error("Error", data);
	close(fd);
}
