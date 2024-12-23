/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_manipulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:49:43 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/23 13:18:26 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_game *game)
{
	mlx_texture_t	*player_tex;
	mlx_texture_t	*wall_tex;
	mlx_texture_t	*collectible_tex;
	mlx_texture_t	*exit_tex;
	mlx_texture_t	*floor_tex;

	player_tex = mlx_load_png("./textures/gatinho1.png");
	wall_tex = mlx_load_png("./textures/wall.png");
	floor_tex = mlx_load_png("./textures/floor.png");
	collectible_tex = mlx_load_png("./textures/fish1.png");
	exit_tex = mlx_load_png("./textures/door1.png");
	if (!player_tex || !wall_tex || !collectible_tex || !exit_tex)
		return (ft_putstr_fd("[ERR0R] UNABLE TO LOAD TEXTURES.\n", 2), 0);
	game->p = mlx_texture_to_image(game->mlx, player_tex);
	game->w = mlx_texture_to_image(game->mlx, wall_tex);
	game->f = mlx_texture_to_image(game->mlx, floor_tex);
	game->c = mlx_texture_to_image(game->mlx, collectible_tex);
	game->e = mlx_texture_to_image(game->mlx, exit_tex);
	if (!game->p || !game->w || !game->f || !game->c || !game->e)
		ft_putstr_fd("[ERR0R] UNABLE TO CREATE IMAGES.\n", 2);
	return (1);
}

void	cleanup_textures(t_game *game)
{
	mlx_delete_image(game->mlx, game->p);
	mlx_delete_image(game->mlx, game->w);
	mlx_delete_image(game->mlx, game->f);
	mlx_delete_image(game->mlx, game->c);
	mlx_delete_image(game->mlx, game->e);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == '1')
				mlx_image_to_window(game->mlx, game->w, x * 64, y * 64);
			else if (game->map->grid[y][x] == '0')
				mlx_image_to_window(game->mlx, game->f, x * 64, y * 64);
			else if (game->map->grid[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->c, x * 64, y * 64);
			else if (game->map->grid[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->e, x * 64, y * 64);
			else if (game->map->grid[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->p, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
