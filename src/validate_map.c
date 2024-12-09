/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:16:49 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/09 19:16:11 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//verifica se o mapa segue as regras estabelecidas (retangular, cerdado por parades, personagem etc..)
//Ela organiza e chama subfunções específicas que verificam diferentes aspectos do mapa

#include "so_long.h"
#include "copy_flood_free_map.c"
//t_map = contém as informações necessárias do mapa

void validate_map(t_map *map)
{
	retangle_to_check(map);
	walls_to_check(map);
	components_to_check(map);
	path_valid_to_check(map);
}

void	retangle_to_check(t_map *map)
{
	int	i;

	i = 1;
	while (i < map->height) 
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
			error("[ERR0R] THIS MAP IS NOT RECTANGULAR\n");
		i++;
	} 
}

void	walls_to_check(t_map *map)
{
	int line;
	int	column;
	
	line = 0;
	column = 0;
	while (column < map->width)
	{
		if (map->grid[line][column] != '1')
			error("[ERR0R] THE TOP MAP IS NOT ENCLOSED BY WALLS\n");
		column++;
	}
	line = map->height - 1;
	column = 0;
	while (column < map->width)
	{
		if (map->grid[line][column] != '1')
			error("[ERR0R] THE BOTTOM MAP IS NOT ENCLOSED BY WALLS\n");
		column++;
	}
	line = 1;
	while (line < map->height -1)
	{
		if (map->grid[line][0] != '1' || map->grid[line][map->width - 1] != '1')
			error("[ERR0R] THE SIDES OF THE MAP ARE NOT ENCLOSED BY WALLS\n");
		line++;
	}
}

void	components_to_check(t_map *map)
{
	int	counter_player;
	int	counter_exit;
	int	line;
	int	column;
	
	counter_player = 0;
	counter_exit = 0;
	line = 0;
	column = 0;
	
	map->collectibles_item = 0;

	while (line < map->height)
	{
		while (column < map->width)
		{
			if (map->grid[line][column] == 'P')
			{
				counter_player++;
				map->position_player_in_x = column;
				map->position_player_in_y = line;
			}
			else if (map->grid[line][column] == 'E')
				counter_exit++;
			else if (map->grid[line][column] == 'C')
				map->collectibles_item++;
			column++;
		}
		line++;
	}
	if (counter_player != 1 || counter_exit != 1 || map->collectibles_item < 1)
		error("[ERR0R] THIS MAP IS MISSING COMPONENTS\n");	
}

void	path_valid_to_check(t_map *map)
{
	char **copy_map;
	
	copy_map = copy_the_original_map(map->grid, map->height);
	flood_fill(copy_map, map->position_player_in_x, map->position_player_in_y);
	free_map_copy(copy_map, map->height);
}