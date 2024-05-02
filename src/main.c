/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:20:25 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/04/30 10:48:37 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t main(void)
{
  // Start mlx
  mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Wan THE GAME", false);
  if (!mlx)
        error();

  // Try to load the file
  mlx_texture_t* texture = mlx_load_png("./sprites/wan.png");
  if (!texture)
        error();

  // Convert texture to a displayable image
  mlx_image_t* img = mlx_texture_to_image(mlx, texture);
  if (!img)
        error();

  // Display the image
  if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

  mlx_loop(mlx);

  mlx_delete_image(mlx, img);
  mlx_delete_texture(texture);

  // Optional, terminate will clean up any leftover images (not textures!)
  mlx_terminate(mlx);
  return (EXIT_SUCCESS);
}
