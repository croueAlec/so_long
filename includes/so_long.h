/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:56:44 by acroue            #+#    #+#             */
/*   Updated: 2024/01/11 15:56:13 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../includes/so_long_defines.h"

typedef struct s_map
{
	char	**map;
	size_t	length;
	size_t	height;
	size_t	coins;
	size_t	exit;
	size_t	enemies;
	size_t	player;
	size_t	player_x;
	size_t	player_y;
}	t_map;

void	ft_err(char *error, void *ptr);
char	*getting_line(char *path, t_map *map);
char	**check_map(char **map_array, t_map *map);
char	*check_line(char *line, t_map *map);


#endif
