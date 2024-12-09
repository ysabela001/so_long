/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:49:27 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/09 18:57:14 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ler o arquivo .ber e carregar os dados em memória como uma matriz (char **)

#include "so_long.h"

//path_to_map_file = caminho para o arquivo do mapa (.ber)
//Ele é utilizado para abrir e ler o arquivo contendo os dados do mapa.

//fd = usado para manipular o arquivo .ber
//store_line = armazena cada linha do arquivo
//**map = representa a array do mapa 

char	**read_and_storematriz_map(const char *path_to_map_file)
{
	int		fd;
	char	*store_line;
	char	**map;
	int		i;
	
	i = 0;
	fd = open(path_to_map_file, O_RDONLY);
	if (fd < 0)
		error_exit("[ERR0R] IS NOT POSSIBLE TO OPEN THE MAP FILE\n");
	map = malloc(sizeof(char *) * MAX_MAP_HEIGHT);
	if (!map)
		error_exit("[ERROR] FAILED ON MEMORY\n");
	while ((store_line = get_next_line(fd)) != NULL)
	{
		map[i] = store_line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	if (i == 0)	
		error("[ERR0R] THIS FILE IS EMPTY\n");
	return (map);
}

// if (i >= MAX_MAP_HEIGHT)
//   error_exit("[ERR0R] MAP HEIGHT EXCEEDS THE MAXIMUM ALLOWED\n");