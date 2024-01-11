/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:56:44 by acroue            #+#    #+#             */
/*   Updated: 2024/01/11 11:17:42 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# define WALL '1'
# define SPACE '0'
# define COIN 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define TILE_SIZE 32

# define BAD_MAP_PATH "Bad map path"
# define MAP_NOT_RECT "Map is not a rectangle"

# define MISSING_COIN "Not enough coins"
# define MISSING_EXIT "No exit"
# define MISSING_SPAWN_POINT "No player spawn point"
# define DUPLICATE_EXIT "Too many exits"
# define DUPLICATE_SPAWN_POINT "Too many player spawn points"
# define WRONG_MAP_CHAR "Unrecognized character in map file"
# define BORDER_ERROR "Map is not completely closed"

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
