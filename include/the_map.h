/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:53:36 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/09 19:40:37 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THE_MAP_H
# define THE_MAP_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "error.h"

# define MAX_MAP_HEIGHT 100

typedef struct s_map {
	char	**grid; //mariz
	int		width; // largura (mapa)
	int		height; // altura (mapa) numero de linhas
	int		collectibles_item; 
	int		position_player_in_x;
	int		position_player_in_y;
	int		exits;
}t_map; // o mapa

// funçoes para ler e validar o mapa
char	**read_and_storematriz_map(const char *path_to_map_file);
void	validate_map(t_map *map);
void	retangle_to_check(t_map *map);
void	walls_to_check(t_map *map);
void	components_to_check(t_map *map);
void	path_valid_to_check(t_map *map);

void	flood_fill(char **map, int x, int y);
char	**copy_map(char **original_map, int  height);
void	free_map_copy(char	**map_copy, int height);

# endif