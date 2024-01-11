/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:08 by acroue            #+#    #+#             */
/*   Updated: 2024/01/11 19:57:41 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		i;
	t_map	*map;

	i = 0;
	map = ft_calloc(sizeof(t_map), 1);
	if(!map)
		return (0);
	if (argc == 1)
		return (perror("Missing map path"), 0);
	while (++i < argc)
		getting_line(argv[i], map);
	manage_window(map);
	return (ft_free(map->map, map->height), free(map), 0);
}
