/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:28:47 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/03/04 17:37:59 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H // If not defined
# define SO_LONG_H // Define it

/**
 * Includes
 */
# include "../libft/ft_printf.h"      // Printf library
# include "../libft/get_next_line.h"  // Get next line library
# include "../libft/libft.h"          // Libft library
# include "mlx/include/MLX42/MLX42.h" // MLX42 library
# include <fcntl.h>                   // File control options
# include <stdbool.h>                 // Boolean type
# include <stdlib.h>                  // Standard library

/**
 * Macros
 */
# define MALLOC_ERROR 1                // Error code for malloc
# define WALL '1'                      // Wall character
# define PLAYER 'P'                    // Player character
# define EXIT 'E'                      // Exit character
# define EMPTY '0'                     // Empty character
# define COLLECTIBLE 'C'               // Collectible character
# define WIDTH 800                     // Window width
# define HEIGHT 600                    // Window height
# define TITLE "Turkish Arruspuchuchu" // Window title
# define PX_SIZE 64                    // Size of the square

/**
 * Structs
 */
typedef struct s_img // Image struct
{
	const uint32_t width;  // Width of the image
	const uint32_t height; // Height of the image
	uint8_t *pixels;       // Pixels of the image
} t_img;                   // Image struct

typedef struct s_data // Data struct
{
	char **map;         // Map
	int rows;           // Rows
	int cols;           // Columns
	int p_position[2];  // Player position
	int collectibles;   // Collectibles
	int players;        // Players
	int exits;          // Exits
	int found;          // Found
	bool allocated_map; // Allocated map
} t_data;               // Data struct

typedef struct s_textures // Textures struct
{
	mlx_texture_t *empty;       // Empty texture
	mlx_texture_t *wall;        // Wall texture
	mlx_texture_t *collectible; // Collectible texture
	mlx_texture_t *player;      // Player texture
	mlx_texture_t *exit;        // Exit texture
	mlx_texture_t *open_exit;   // Open exit texture
} t_textures;                   // Textures struct

typedef struct s_images // Images struct
{
	mlx_image_t *empty;       // Empty image
	mlx_image_t *wall;        // Wall image
	mlx_image_t *collectible; // Collectible image
	mlx_image_t *player;      // Player image
	mlx_image_t *exit;        // Exit image
	mlx_image_t *open_exit;   // Open exit image
} t_images;                   // Images struct

typedef struct s_game // Game struct
{
	mlx_t *mlx;                  // MLX
	int width;                   // Width
	int height;                  // Height
	int move_counter;            // Move counter
	int collected;               // Collected collectibles
	char **map;                  // Map
	struct s_textures *textures; // Textures
	struct s_images *image;      // Images
	struct s_data *data;         // Data
}		t_game;

/**
 * Error Functions
 * Such as exiting the program, freeing memory, etc...
 */
void	exit_error(char *message, t_data *data);     // Exit error
void	ft_free_matrix(t_data *data, void **matrix); // Free matrix
void	ft_end_game(t_game *game);                   // End game

/**
 * Key Functions
 * Such as moving the player, checking if it's valid, etc...
 */
void	ft_action(mlx_key_data_t keydata, void *param); // Action
void	ft_move_up(t_game *game);                       // Move up
void	ft_move_down(t_game *game);                     // Move down
void	ft_move_left(t_game *game);                     // Move left
void	ft_move_right(t_game *game);                    // Move right
void	ft_collect(t_game *game);                       // Collect
void	ft_remove_collectible(t_game *game);            // Remove collectible

/**
 * Map Functions
 * Such as reading the map, checking if it's valid, etc...
 */
void	ft_read_map(t_data *data, char **argv);             // Read map
void	ft_map_check(t_data *data, char **map);             // Map check
int	ft_allocate_lines(t_data *data, char **argv);        // Allocate lines
void	ft_playable_check(t_data *data, char **map);        // Playable check
void	init_explore(t_data *data, int ***visited);         // Init explore
void	explore(t_data *data, int x, int y, int **visited); // Explore
void	pec_config_check(t_data *data, char **map);         // PEC config check

/**
 * Game Functions
 * Such ass Init the game or ending it
 * Etc...
 */
void	ft_init_game(t_game *game, t_data *data);
// Initiating the game
void	end_game(t_game *game, t_data *data);
// Ending the game
void	ft_get_textures(t_game *game);
// Get the textures
void	ft_get_images(t_game *game);
// Get the images
void	draw_map(t_data *data, t_game *game, t_images *image); // Draw the map
void	draw_floor(t_data *data, t_game *game, t_images *image);
// Draw the floor (empty)

#endif
