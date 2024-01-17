/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:56:44 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 13:34:26 by acroue           ###   ########.fr       */
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

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		size;
}	t_img;

typedef struct s_flood
{
	char	**map;
	size_t	coins;
	size_t	exit;
}	t_flood;

typedef struct s_data
{
	void	**assets;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
	size_t	exit_y;
	size_t	exit_x;
	int		steps;
}	t_data;

char	*ft_sep_join(char *s1, char *s2, char *sep);
void	ft_err(char *error, void *ptr);
char	**getting_line(char *path, t_map *map);
char	**check_map(char **map_array, t_map *map, char *res);
char	*check_line(char *line, t_map *map);
int		manage_window(t_map *map);
void	**load_assets(t_data data);
void	clear_images(t_data data, void **assets, size_t size);
int		put_image(t_data data, void *mlx_img, size_t y_axis, size_t x_axis);
int		ft_end(t_data data, void **assets);
void	*load_image(t_data data, char *path);
void	**load_player(t_data data, void **assets);
void	player_reaction(t_data *data, void **assets, char move);
void	move_player(t_data *data, int y_diff, int x_diff, int texture);
int		can_move(t_map *map, int y_diff, int x_diff, t_data *data);
void	find_exit(char **map_array, t_data *data);
int		path_finding(t_data *data, t_map *map, char **map_array);
int		put_string(t_data *data);
int		ft_hook(int keycode, t_data *data);
void	win_map(t_data *data, int y_diff, int x_diff);
void	put_map(t_map *map, t_data data, void **tab);

#endif
