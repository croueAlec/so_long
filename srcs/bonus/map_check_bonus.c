/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:11:12 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 14:23:18 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_border_line(char *line, size_t length, char wall)
{
	size_t	i;

	i = 0;
	if (line[length - 1] != '\0')
		return (0);
	while (i < length - 1)
	{
		if (line[i] != WALL)
			return (0);
		line[i] = wall;
		if (i == 0)
		{
			line[i] = C_CORNER;
			if (wall == U_WALL)
				line[i] = A_CORNER;
		}
		if (i == length - 2)
		{
			line[i] = D_CORNER;
			if (wall == U_WALL)
				line[i] = B_CORNER;
		}
		i++;
	}
	return (1);
}

int	check_border_column(char **map_array, t_map *map)
{
	size_t	i;

	i = 1;
	while (i < map->height - 1)
	{
		if (map_array[i][0] != WALL || map_array[i][map->length - 2] != WALL)
			return (0);
		map_array[i][0] = L_WALL;
		map_array[i][map->length - 2] = R_WALL;
		i++;
	}
	return (1);
}

int	check_border(char **map_array, t_map *map)
{
	if (!check_border_line(map_array[0], map->length, U_WALL))
		return (ft_free(map_array, map->height), ft_err(BORDER_ERROR, map), 0);
	if (!check_border_line(map_array[map->height - 1], map->length, D_WALL))
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
				break ;
			x++;
		}
		if (map_array[y][x] == PLAYER)
			break ;
		y++;
	}
	map->player_y = y;
	map->player_x = x;
	check_border(map_array, map);
	return (map_array);
}

void	find_exit(char **map_array, t_data *data)
{
	size_t	x;
	size_t	y;
	t_map	*map;

	map = data->map;
	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->length - 1)
		{
			if (map_array[y][x] == EXIT)
				break ;
			x++;
		}
		if (map_array[y][x] == EXIT)
			break ;
		y++;
	}
	data->exit_y = y;
	data->exit_x = x;
}

/*
	Here we make sure that the shape of the map is ok.
	We also format it so our wall textures are correctly placed
*/
