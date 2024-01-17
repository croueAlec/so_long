/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:43 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 14:21:56 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
	if (!res)
		return (free(s1), NULL);
	res[len_s1 + len_s2 + sep_len] = '\0';
	while (len_s2--)
		res[len_s1 + sep_len + len_s2] = s2[len_s2];
	while (sep_len--)
		res[len_s1 + sep_len] = sep[sep_len];
	while (len_s1--)
		res[len_s1] = s1[len_s1];
	free(s1);
	return (res);
}

void	ft_free_tab(char **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**getting_line(char *path, t_map *map)
{
	char	*line;
	char	*res;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 1)
		ft_err(BAD_MAP_PATH, map);
	res = get_next_line(fd);
	map->length = (size_t)ft_safe_strlen(res);
	map->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (++map->height && line == NULL)
			break ;
		if (ft_strlen(line) != map->length)
			return (free(res), free(map), ft_err(MAP_NOT_RECT, line), NULL);
		res = ft_sep_join(res, line, "");
		free(line);
	}
	map->map = check_map(ft_split(check_line(res, map), '\n'), map, res);
	return (map->map);
}

/*
	Here we have the map's getting and parsing
*/
