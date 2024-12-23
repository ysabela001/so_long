/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:16:49 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/23 11:32:28 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	retangle_to_check(t_map *map)
{
	int	i;

	i = 1;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	walls_to_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	components_to_check(t_map *map)
{
	int	p;
	int	e;
	int	y;
	int	x;

	init_components (map, &p, &e, &y);
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				p++;
				map->player_in_x = x;
				map->player_in_y = y;
			}
			else if (map->grid[y][x] == 'E')
				e++;
			else if (map->grid[y][x] == 'C')
				map->collectibles_count++;
		}
	}
	return (p == 1 && e == 1 && map->collectibles_count >= 1);
}

static int	path_valid_to_check(t_map *map)
{
	char	**copy_map;
	int		line;
	int		column;

	copy_map = copy_the_original_map(map->grid, map->height);
	if (!copy_map)
		return (0);
	flood_fill(copy_map, map->player_in_x, map->player_in_y);
	line = 0;
	while (line < map->height)
	{
		column = 0;
		while (column < map->width)
		{
			if (copy_map[line][column] == 'C' || copy_map[line][column] == 'E')
			{
				free_map_copy(copy_map, map->height);
				return (0);
			}
			column++;
		}
		line++;
	}
	free_map_copy(copy_map, map->height);
	return (1);
}

int	validate_map(t_map *map)
{
	if (!map || map->height == 0 || map->width == 0)
		return (0);
	if (!retangle_to_check(map))
		return (ft_putstr_fd("Error:\nMap is not rectangular!\n", 2), 0);
	if (!walls_to_check(map))
		return (ft_putstr_fd("Error:\nMap is not surrounded by walls!\n", 2), 0);
	if (!components_to_check(map))
		return (ft_putstr_fd("Error:\nInvalid number of elements!\n", 2), 0);
	if (!path_valid_to_check(map))
		return (ft_putstr_fd("Error:\nInvalid path! Unreachable \
			components.\n", 2), 0);
	return (1);
}
