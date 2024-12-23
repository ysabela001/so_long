/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:16:51 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/23 13:19:08 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// keybord events and move the character
#include "so_long.h"

static void	update_moves(t_game *game)
{
	char	*moves_str;

	game->moves_count++;
	if (game->moves_text)
		mlx_delete_image(game->mlx, game->moves_text);
	moves_str = ft_itoa(game->moves_count);
	if (!moves_str)
		return ;
	ft_putstr_fd("Move count:", 1);
	ft_putnbr_fd(game->moves_count, 1);
	ft_putchar_fd('\n', 1);
	game->moves_text = mlx_put_string(game->mlx, moves_str, 10, 10);
	free(moves_str);
}

static void	moves_of_player(t_game *game, int p_dx, int p_dy)
{
	int	new_p_dx;
	int	new_p_dy;

	new_p_dx = game->map->player_in_x + p_dx;
	new_p_dy = game->map->player_in_y + p_dy;
	if (new_p_dx < 0 || new_p_dx >= game->map->width || new_p_dy < 0 || new_p_dy
		>= game->map->height || game->map->grid[new_p_dy][new_p_dx] == '1'
		|| (game->map->grid[new_p_dy][new_p_dx] == 'E'
		&& game->map->collectibles_count > 0))
		return ;
	update_moves(game);
	if (game->map->grid[new_p_dy][new_p_dx] == 'C')
		game->map->collectibles_count--;
	else if (game->map->grid[new_p_dy][new_p_dx] == 'E'
		&& game->map->collectibles_count == 0)
	{
		ft_putstr_fd("Congratulations you win the game!\n", 1);
		mlx_close_window(game->mlx);
		return ;
	}
	game->map->grid[game->map->player_in_y][game->map->player_in_x] = '0';
	game->map->grid[new_p_dy][new_p_dx] = 'P';
	game->map->player_in_x = new_p_dx;
	game->map->player_in_y = new_p_dy;
	render_map(game);
}

void	keyboard_events(mlx_key_data_t data_key, t_game *game)
{
	if (data_key.action == MLX_PRESS || data_key.action
		== MLX_REPEAT)
	{
		if (data_key.key == MLX_KEY_W || data_key.key == MLX_KEY_UP)
			moves_of_player(game, 0, -1);
		else if (data_key.key == MLX_KEY_A || data_key.key == MLX_KEY_LEFT)
			moves_of_player(game, -1, 0);
		else if (data_key.key == MLX_KEY_S || data_key.key == MLX_KEY_DOWN)
			moves_of_player(game, 0, 1);
		else if (data_key.key == MLX_KEY_D || data_key.key == MLX_KEY_RIGHT)
			moves_of_player(game, 1, 0);
		else if (data_key.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
	}
}
