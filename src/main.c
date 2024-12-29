/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:48:56 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/29 14:19:34 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_game(t_game *game)
{
	int	i;

	game->mlx = NULL;
	game->moves_count = 0;
	game->moves_text = NULL;
	game->map = NULL;
	i = -1;
	while (++i < 5)
		game->imgs[i] = NULL;
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
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (ft_putstr_fd("[ERROR]Failed to allocate memory for map.\n", 2));
	map->grid = read_and_storematriz_map(path_to_map_file);
	if (!(map->grid))
		return (free(map), ft_putstr_fd("[ERR0R]map not load!\n", 2));
	calculate_map_dimensions(map);
	if ((map->height == 0) || (map->width == 0) || validate_map(map) == 0)
		return (free_map(map), ft_putstr_fd("[ERR0R]Invalid map!\n", 2));
	game.mlx = mlx_init(map->width * TILE_SIZE, map->height * \
		TILE_SIZE, "so_long", false);
	if (!(game.mlx))
		return (free_map(map), ft_putstr_fd("[ERROR]not initialize MLX.\n", 2));
	game.map = map;
	if (!load_textures(&game))
		return (cleanup_game(&game), (void)0);
	// render_map(&game);
	// mlx_key_hook(game.mlx, (mlx_keyfunc)keyboard_events, &game);
	// mlx_loop(game.mlx);
	// cleanup_game(&game);
	// free(map);
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
