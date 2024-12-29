/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:10:01 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/29 13:34:02 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/lib/libft.h"
# include "get_next_line.h"

# define TILE_SIZE 64
# define MAX_MAP_HEIGHT 100

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles_count;
	int		player_in_x;
	int		player_in_y;
	int		exits;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	int			moves_count;
	mlx_image_t	*moves_text;
	mlx_image_t	*imgs[5];
	t_map		*map;
}	t_game;

enum e_texture_index
{
	P_T = 0,
	W_T,
	F_T,
	C_T,
	E_T
};

void	init_graphics(t_map *map);
int		load_textures(t_game *game);
void	render_map(t_game *game);

char	**read_and_storematriz_map(const char *path_to_map_file);
void	read_lines_into_map(int fd, char **map);
int		validate_map(t_map *map);

void	flood_fill(char **map, int x, int y);
char	**copy_the_original_map(char **original_map, int height);
void	free_map_copy(char **grid, int height);

void	keyboard_events(mlx_key_data_t data_key, t_game *game);

void	calculate_map_dimensions(t_map *map);
int		calculate_dimensions(t_map *map, int max_swidth, int max_sheight);

void	free_map(t_map *map);
void	cleanup_game(t_game *game);
void	cleanup_textures(t_game *game);

void	init_components(t_map *map, int *p, int *e, int *y);

#endif