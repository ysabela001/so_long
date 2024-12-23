/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:55:58 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/23 18:41:04 by ytavares         ###   ########.fr       */
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
	calculate_dimensions(map, max_swidth, max_sheight);
}

void	calculate_dimensions(t_map *map, int max_swidth, int max_sheight)
{
	int	max_width;
	int	height;
	int	current_width;

	max_width = 0;
	height = 0;
	while (map->grid[height] != NULL)
	{
		current_width = ft_strlen(map->grid[height]);
		if (current_width > max_width)
			max_width = current_width;
		height++;
	}
	if (max_width * TILE_SIZE > max_swidth || height * TILE_SIZE > max_sheight)
	{
		ft_putstr_fd("[ERROR] Map too large for screen\n", 2);
		return ;
	}
	map->width = max_width;
	map->height = height;
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
	if (game->map)
	{
		free_map_copy(game->map->grid, game->map->height);
		free(game->map);
	}
	if (!game->mlx)
		cleanup_textures(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
}
