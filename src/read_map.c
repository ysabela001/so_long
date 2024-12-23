/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:49:27 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/20 15:35:19 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ler o arquivo .ber e carregar os dados em memória como uma matriz (char **)

#include "so_long.h"

char	**read_and_storematriz_map(const char *path_to_map_file)
{
	int		fd;
	char	**map;
	int		i;

	i = 0;
	fd = open(path_to_map_file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("[ERR0R] CANNOT OPEN THE MAP FILE\n", 2), NULL);
	map = malloc(sizeof(char *) * MAX_MAP_HEIGHT);
	if (!map)
		return (ft_putstr_fd("[ERROR] FAILED ON MEMORY\n", 2), NULL);
	read_lines_into_map(fd, map);
	close(fd);
	if (map[0] == NULL)
	{
		free(map);
		return (ft_putstr_fd("[ERR0R] THIS FILE IS EMPTY\n", 2), NULL);
	}
	return (map);
}

void	read_lines_into_map(int fd, char **map)
{
	char	*store_line;
	size_t	len;
	int		i;

	i = 0;
	store_line = get_next_line(fd);
	while (store_line != NULL)
	{
		len = ft_strlen(store_line);
		if (len > 0 && store_line[len - 1] == '\n')
			store_line[len - 1] = '\0';
		map[i] = store_line;
		i++;
		store_line = get_next_line(fd);
	}
	map[i] = NULL;
}
