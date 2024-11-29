/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:16:49 by ytavares          #+#    #+#             */
/*   Updated: 2024/11/29 19:49:00 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//verifica se o mapa segue as regras estabelecidas (retangular, cerdado por parades, personagem etc..)
//Ela organiza e chama subfunções específicas que verificam diferentes aspectos do mapa

#include "so_long.h"
//t_map = contém as informações necessárias do mapa

void validate_map(t_map *map)
{
	retangle_to_check(map);
	walls_to_check(map);
	components_to_check(map);
	path_valid_to_check(map);
	//test
}