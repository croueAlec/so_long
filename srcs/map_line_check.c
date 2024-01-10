/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:12:10 by acroue            #+#    #+#             */
/*   Updated: 2024/01/10 20:14:02 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

int	map_charset(char c)
{
	if (c == WALL || c == SPACE || c == COIN || c == EXIT || c == PLAYER)
		return (1);
	return (0);
}

void	map_error(char *line, t_map *map)
{
	if (map->coins < 1)
		ft_err(MISSING_COIN, line);
	if (map->exit < 1)
		ft_err(MISSING_EXIT, line);
	else if (map->exit > 1)
		ft_err(DUPLICATE_EXIT, line);
	if (map->player < 1)
		ft_err(MISSING_SPAWN_POINT, line);
	else if (map->player > 1)
		ft_err(DUPLICATE_SPAWN_POINT, line);
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
		i++;
	}
	map_error(line, map);
	return (line);
}
