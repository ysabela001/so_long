/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:10:01 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/23 18:32:47 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "include/MLX42/MLX42.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/lib/libft.h"
#include "get_next_line.h"

#define TILE_SIZE 64
#define MAX_MAP_HEIGHT 100

typedef struct s_map
{
	char **grid; // mariz
	int width;	 // largura (mapa)
	int height;	 // altura (mapa) numero de linhas
	int collectibles_count;
	int player_in_x;
	int player_in_y;
	int exits;
} t_map;

typedef struct s_game
{
	mlx_t 		*mlx; // ponteiro para a instancia MLX (bibioteca)
	int			moves_count; 
	mlx_image_t	*moves_text; // menssage to count moves
	mlx_image_t *p;
	mlx_image_t *w;
	mlx_image_t *c;
	mlx_image_t *e;
	mlx_image_t *f;
	t_map *map;
} t_game;

void	init_graphics(t_map *map);	  // start graphic
int		load_textures(t_game *game); // load the textures
void	render_map(t_game *game);	  // render the scream

// read and validation
char	**read_and_storematriz_map(const char *path_to_map_file);
void	read_lines_into_map(int fd, char **map);
int		validate_map(t_map *map);

// copy, flood and free
void	flood_fill(char **map, int x, int y);
char	**copy_the_original_map(char **original_map, int height);
void	free_map_copy(char **map_copy, int height);

//keybord
void	keyboard_events(mlx_key_data_t data_key, t_game *game);

//count (width and height)
void	calculate_map_dimensions(t_map *map);
void	calculate_dimensions(t_map *map, int max_swidth, int max_sheight);

//cleanup images and textures
void	cleanup_game(t_game *game);
void	cleanup_textures(t_game *game);

//check components
void	init_components(t_map *map, int *p, int *e, int *y);

#endif