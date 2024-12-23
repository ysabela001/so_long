/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:48:56 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/23 18:36:10 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->grid)
		free_map_copy(map->grid, map->height);
	free(map);
}

static void	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->moves_count = 0;
	game->moves_text = NULL;
	game->p = NULL;
	game->w = NULL;
	game->c = NULL;
	game->e = NULL;
	game->f = NULL;
	game->map = NULL;
}

static int	validate_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (!ft_strncmp(filename + len - 4, ".ber", 4));
}

void	start_game(const char *path_to_map_file)
{
	t_map	*map;
	t_game	game;

	ft_init_game(&game);
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_putstr_fd("[ERROR]Failed to allocate memory for map.\n", 2));
	ft_memset(map, 0, sizeof(t_map));
	map->grid = read_and_storematriz_map(path_to_map_file);
	if (!(map->grid))
		return (free_map(map), ft_putstr_fd("[ERR0R]map not load!\n", 2));
	calculate_map_dimensions(map);
	if (map->width == 0 || map->height == 0 || validate_map(map) == 0)
		return (free_map(map), ft_putstr_fd("[ERR0R]Invalid map!\n", 2));
	game.mlx = mlx_init(map->width * TILE_SIZE, map->height * \
		TILE_SIZE, "so_long", false);
	if (!(game.mlx))
		return (free_map(map), ft_putstr_fd("[ERROR]no initialize MLX.\n", 2));
	game.map = map;
	if (!load_textures(&game))
		return (cleanup_game(&game), (void)0);
	render_map(&game);
	mlx_key_hook(game.mlx, (mlx_keyfunc)keyboard_events, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map_file>\n", 28);
		return (1);
	}
	if (!validate_extension(argv[1]))
		return (ft_putstr_fd("[ERR0R] map must have .ber extension!\n", 2), 1);
	start_game(argv[1]);
	return (0);
}
