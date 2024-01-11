/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:11:12 by acroue            #+#    #+#             */
/*   Updated: 2024/01/11 19:04:04 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

int	check_border_line(char *line, size_t length)
{
	size_t	i;

	i = 0;
	if (line[length - 1] != '\0')
		return (0);
	while (i < length - 1)
	{
		if (line[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	check_border_column(char **map_array, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		printf("%s\n", map_array[i]);
		printf("%c\t%c\n", map_array[i][0], map_array[i][map->length - 2]);
		if (map_array[i][0] != WALL || map_array[i][map->length - 2] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int check_border(char **map_array, t_map *map)
{
	if (!check_border_line(map_array[0], map->length))
		return (ft_free(map_array, map->height), ft_err(BORDER_ERROR, map), 0);
	if (!check_border_line(map_array[map->height - 1], map->length))
		return (ft_free(map_array, map->height), ft_err(BORDER_ERROR, map), 0);
	if (!check_border_column(map_array, map))
		return (ft_free(map_array, map->height), ft_err(BORDER_ERROR, map), 0);
	return (1);
}

char	**check_map(char **map_array, t_map *map, char *res)
{
	size_t	x;
	size_t	y;

	y = 0;
	free(res);
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->length - 1)
		{
			if (map_array[y][x] == PLAYER)
				break;
			x++;
		}
		if (map_array[y][x] == PLAYER)
			break;
		y++;
	}
	map->player_y = y;
	map->player_x = x;
	printf("%zu %zu\n", map->player_x, map->player_y);
	check_border(map_array, map);
	return (map_array);
}

/* les bordures de la carte sont check mtn il faut check si la carte est solvable + rajouter dans le makefile mapcheck et mapline check*/
