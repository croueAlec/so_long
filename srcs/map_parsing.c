/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:43 by acroue            #+#    #+#             */
/*   Updated: 2024/01/10 16:39:18 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

int	check_map(char *map)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			printf(" %zu\n", i + 1);
			if (length == 0 && i)
				length = i + 1;
			else if (i + 1 % length)
			{
				printf("%zu\n", i + 1 % length);
				printf("\n%zu %zu\n", i + 1, length);
				perror("Map is not rectangular");
				free(map);
				exit(0);
			}
		}
		else
			printf("%c", map[i]);
		i++;
	}
	return (1);
}

char	*ft_sep_join(char *s1, char *s2, char *sep)
{
	char	*res;
	int		len_s1;
	int		len_s2;
	int		sep_len;

	len_s1 = ft_safe_strlen(s1);
	len_s2 = ft_safe_strlen(s2);
	sep_len = ft_safe_strlen(sep);
	res = malloc((len_s1 + len_s2 + sep_len + 1) * sizeof(char));
	if(!res)
		return (free(s1), NULL);
	res[len_s1 + len_s2 + sep_len] = '\0';
	while (len_s2--)
		res[len_s1 + sep_len + len_s2] = s2[len_s2];
	while (sep_len--)
		res[len_s1 + sep_len] = sep[sep_len];
	while (len_s1--)
		res[len_s1] = s1[len_s1];
	return (res);
}

void	ft_err(char *error, void *ptr)
{
	if (ptr)
		free(ptr);
	perror(error);
	exit(0);
}

int	check_border_line(char *line, size_t length)
{
	size_t	i;

	i = 0;
	while (i <= length)
	{
		if (line[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	map_charset(char c)
{
	if (c == WALL || c == SPACE || c == COIN || c == EXIT || c == PLAYER)
		return (1);
	// if (c == '\n')
	// 	return (1);
	return (0);
}

int	check_line(char *line, t_map map)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!map_charset(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	map_error(t_map *map)
{
	if (map->coins < 1)
		ft_err(MISSING_COIN, NULL);
	if (map->exit < 1)
		ft_err(MISSING_EXIT, NULL);
	else if (map->exit > 1)
		ft_err(DUPLICATE_EXIT, NULL);
	if (map->player < 1)
		ft_err(MISSING_SPAWN_POINT, NULL);
	else if (map->player > 1)
		ft_err(DUPLICATE_SPAWN_POINT, NULL);
	ft_free(map->map, map->height);
	
}

char	**check_map(char **map_text, t_map *map)
{
	if (map->coins < 1 || map->exit != 1 || map->player != 1)
		map_error
}

char	*getting_line(char *path, t_map *map)
{
	char	*line;
	char	*res;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 1)
		ft_err(, NULL);
	res = get_next_line(fd);
	map->length = (size_t)ft_safe_strlen(res);
	map->height = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (map->height++ && line == NULL)
			break;
		if (ft_strlen(line) != map->length)
			return (free(res), ft_err("Map is not a rectangle", line), NULL);
		res = ft_sep_join(res, line, "");
		free(line);
	}
	map->map = check_map(ft_split(res, '\n'), map);
	return (res);
}

/* verifier le error handling et ajouter le check pour les coins joueur et sortie */
