/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:49:27 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/28 19:14:05 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_and_storematriz_map(const char *path_to_map_file)
{
	int		fd;
	char	**map;

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
	free(get_next_line(fd));
	return (map);
}

void	read_lines_into_map(int fd, char **map)
{
	char	*line;
	size_t	len;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map[i] = NULL;
}
