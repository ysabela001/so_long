/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_flood_free_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:03:16 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/09 19:17:40 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_the_original_map(char **original_map, int height)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = (char *)malloc((height + 1) * sizeof(char *));
	if (!copy_map)
		error("[ERR0R] FAILED TO ALLOCATE MEMORY (MAP_COPY)\n");
	while (i < height)
	{
		copy_map[i] = ft_strdup(original_map[i]);
		if (!copy_map[i])
			error("[ERR0R] FAILED TO ALLOCATE MEMORY (MAP_COPY)\n");
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void flood_fill(char **map, int x, int y)
{
	if ( x < 0 || y < 0 ||!map[y] || x >= (int)ft_strlen(map[y])
	|| map[y][x] == '1' || map[y][x] == 'V')

	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
		map[y][x] = 'V';

	flood_fill (map, x + 1, y);
	flood_fill (map, x - 1, y);
	flood_fill (map, x, y + 1);
	flood_fill (map, x, y - 1);
}

void free_map_copy(char **copy_map, int height)
{
	int i;
	
	i = 0;
	while(i < height)
	{
		free (copy_map[i]);
		i++;
	}
	free (copy_map);
}

