/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:08 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 14:23:21 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_map	*map;

	i = 0;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (0);
	if (argc == 1)
		return (ft_putstr_fd(BAD_MAP_PATH, 2), 0);
	while (++i < argc)
		getting_line(argv[i], map);
	manage_window(map);
	return (ft_free(map->map, map->height), free(map), 0);
}

/*
	Here we have our main function, and that's it.
	Not much going on here.
*/
