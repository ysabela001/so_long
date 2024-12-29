/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_manipulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:49:43 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/29 13:34:31 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_game *game)
{
	int				i;
	mlx_texture_t	*textures[5];
	const char		*paths[5];	

	paths[0] = "./textures/cat1.png";
	paths[1] = "./textures/wall.png";
	paths[2] = "./textures/floor.png";
	paths[3] = "./textures/fish1.png";
	paths[4] = "./textures/door1.png";
	i = -1;
	while (++i < 5)
	{
		textures[i] = mlx_load_png(paths[i]);
		if (!textures[i])
			return (ft_putstr_fd("[ERR0R] UNABLE TO LOAD TEXTURES.\n", 2), 0);
		game->imgs[i] = mlx_texture_to_image(game->mlx, textures[i]);
		mlx_delete_texture(textures[i]);
		if (!game->imgs[i])
			return (ft_putstr_fd("[ERR0R] UNABLE TO CREATE IMAGES.\n", 2), 0);
	}
	return (1);
}

void	cleanup_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (game->imgs[i])
		{
			mlx_delete_image(game->mlx, game->imgs[i]);
			game->imgs[i] = NULL;
		}
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			mlx_image_to_window(game->mlx, game->imgs[F_T], x * 64, y * 64);
			if (game->map->grid[y][x] == '1')
				mlx_image_to_window(game->mlx, game->imgs[W_T], x * 64, y * 64);
			else if (game->map->grid[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->imgs[C_T], x * 64, y * 64);
			else if (game->map->grid[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->imgs[E_T], x * 64, y * 64);
			else if (game->map->grid[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->imgs[P_T], x * 64, y * 64);
		}
	}
}
