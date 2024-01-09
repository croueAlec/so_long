/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:43 by acroue            #+#    #+#             */
/*   Updated: 2024/01/09 20:04:27 by acroue           ###   ########.fr       */
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

char	*getting_line(char *path)
{
	char	*line;
	char	*res;
	int		fd;
	size_t	length;

	fd = open(path, O_RDONLY);
	if (fd < 1)
		ft_err("Bad map path", NULL);
	res = get_next_line(fd);
	length = (size_t)ft_safe_strlen(res);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (ft_strlen(line) != length)
			return (free(res), ft_err("Map is not a rectangle", line), NULL);
		res = ft_sep_join(res, line, "");
		free(line);
	}
	// printf("%s", res);
	check_map(res);
	return (res);
}
