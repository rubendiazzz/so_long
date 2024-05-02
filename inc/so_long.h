/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:01:42 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/04/30 11:18:17 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
#include "./MLX42/include/MLX42/MLX42.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

// Window
#define WIDTH 1920
#define HEIGHT 1080
#define TITLE "So Long"

// Control
#define DOWN MLX_KEY_S
#define UP MLX_KEY_W
#define LEFT MLX_KEY_A
#define RIGHT MLX_KEY_D

// Character
#define CHARACTER "./sprites/character.png"

// Background
#define BACKGROUND "./sprites/floor.png"

// Wall
#define WALL "./sprites/wall.png"

#endif
