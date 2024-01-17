/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:12:10 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 18:56:15 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	map_charset(char c)
{
	if (c == WALL || c == SPACE || c == COIN || c == EXIT || c == PLAYER)
		return (1);
	if (c == ENEMY)
		return (1);
	return (0);
}

static void	map_error_2(char *line, t_map *map)
{
	if (map->coins < 1)
	{
		free(map);
		ft_err(MISSING_COIN, line);
	}
	if (map->enemies < 1)
	{
		free(map);
		ft_err(MISSING_ENEMY, line);
	}
	if (map->enemies > 1)
	{
		free(map);
		ft_err(TOO_MANY_ENEMIES, line);
	}
}

void	map_error(char *line, t_map *map)
{
	map_error_2(line, map);
	if (map->exit < 1)
	{
		free(map);
		ft_err(MISSING_EXIT, line);
	}
	else if (map->exit > 1)
	{
		free(map);
		ft_err(DUPLICATE_EXIT, line);
	}
	if (map->player < 1)
	{
		free(map);
		ft_err(MISSING_SPAWN_POINT, line);
	}
	else if (map->player > 1)
	{
		free(map);
		ft_err(DUPLICATE_SPAWN_POINT, line);
	}
}

char	*check_line(char *line, t_map *map)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!map_charset(line[i]) && line[i] != '\n')
			return (ft_err(WRONG_MAP_CHAR, line), NULL);
		if (line[i] == COIN)
			map->coins++;
		else if (line[i] == EXIT)
			map->exit++;
		else if (line[i] == PLAYER)
			map->player++;
		else if (line[i] == ENEMY)
			map->enemies++;
		i++;
	}
	map_error(line, map);
	return (line);
}

/*
	Here we check the map's lines for coins, exits, players and forbidden chars
*/
