/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:55:58 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/28 19:39:57 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_map_dimensions(t_map *map)
{
	int	max_swidth;
	int	max_sheight;

	mlx_get_monitor_size(0, &max_swidth, &max_sheight);
	if (max_swidth == 0 || max_sheight == 0)
	{
		max_swidth = 1920;
		max_sheight = 1080;
	}
	if (!calculate_dimensions(map, max_swidth, max_sheight))
	{
		free(map);
		exit(1);
	}
}

int	calculate_dimensions(t_map *map, int max_swidth, int max_sheight)
{
	int	max_width;
	int	height;
	int	current_width;

	max_width = 0;
	height = 0;
	while (map->grid[height])
	{
		current_width = ft_strlen(map->grid[height]);
		if (current_width > max_width)
			max_width = current_width;
		height++;
	}
	map->height = height;
	map->width = max_width;
	if (max_width * TILE_SIZE > max_swidth || height * TILE_SIZE > max_sheight)
	{
		ft_putstr_fd("[ERROR] Map too large for screen\n", 2);
		free_map_copy(map->grid, map->height);
		map->grid = NULL;
		return (0);
	}
	return (1);
}

void	init_components(t_map *map, int *p, int *e, int *y)
{
	*p = 0;
	*e = 0;
	*y = -1;
	map->collectibles_count = 0;
}

void	cleanup_game(t_game *game)
{
	if (game->moves_text)
		mlx_delete_image(game->mlx, game->moves_text);
	cleanup_textures(game);
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	exit(0);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->grid[i])
			{
				free(map->grid[i]);
				map->grid[i] = NULL;
			}
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
	free(map);
}
