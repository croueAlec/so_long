/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pates_finding_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:56:06 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 16:46:21 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static char	restore_map(char c)
{
	if (c == WALL || c == U_WALL || c == D_WALL || c == L_WALL || c == R_WALL)
		return (WALL);
	if (c == A_CORNER || c == B_CORNER || c == D_CORNER || c == C_CORNER)
		return (WALL);
	return (c);
}

char	**array_cpy(char **map, size_t height)
{
	char	**res;
	size_t	length;
	size_t	i;
	size_t	j;

	i = 0;
	length = 0;
	res = ft_calloc((height + 1), sizeof(char *));
	if (!res)
		return (NULL);
	res[height] = NULL;
	while (i < height)
	{
		j = 0;
		res[i] = ft_strdup(map[i]);
		if (!res[i])
			return (ft_free(res, i), NULL);
		while (res[i][j])
		{
			res[i][j] = restore_map(res[i][j]);
			j++;
		}
		i++;
	}
	return (res);
}

static void	path(t_map *map, t_flood *flood, size_t y, size_t x)
{
	char	**m;

	m = flood->map;
	if (flood->map[y][x] == WALL)
		return ;
	else if (flood->map[y][x] == EXIT)
		flood->exit++;
	else if (flood->map[y][x] == COIN)
		flood->coins++;
	flood->map[y][x] = WALL;
	if (y - 1 > 0 && m[y - 1][x] != WALL)
		path(map, flood, y - 1, x);
	if (y + 1 < map->height && m[y + 1][x] != WALL)
		path(map, flood, y + 1, x);
	if (x - 1 > 0 && m[y][x - 1] != WALL)
		path(map, flood, y, x - 1);
	if (x + 1 < map->length && m[y][x + 1] != WALL)
		path(map, flood, y, x + 1);
}

int	path_finding(t_data *data, t_map *map, char **map_array)
{
	t_flood	flood;

	flood.coins = 0;
	flood.exit = 0;
	flood.map = array_cpy(map_array, map->height);
	path(map, &flood, map->player_y, map->player_x);
	ft_free(flood.map, data->map->height);
	if (flood.coins == map->coins && flood.exit == map->exit)
		return (1);
	return (0);
}

/*
	Here we have our map's pathfinding, it makes sure the coins and the exit
	are all reachable by the player
*/
