/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:56:44 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 16:55:44 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include "../../libs/libft/libft.h"
# include "../../libs/minilibx-linux/mlx.h"
# include "../../includes/so_long_defines_bonus.h"

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

/* error_handling_bonus.c */
void	ft_err(char *error, void *ptr);
void	clear_images(t_data data, void **assets, size_t size);
int		ft_end(t_data data, void **assets);
/* load_assets_bonus.c */
void	*load_image(t_data data, char *path);
void	**load_assets(t_data data);
/* manage_window_bonus.c */
void	win_map(t_data *data, int y_diff, int x_diff);
int		manage_window(t_map *map);
/* map_building_bonus.c */
int		put_image(t_data data, void *mlx_img, size_t y_axis, size_t x_axis);
void	put_map(t_map *map, t_data data, void **tab);
/* map_check_bonus.c */
char	**check_map(char **map_array, t_map *map, char *res);
void	find_exit(char **map_array, t_data *data);
/* map_line_check_bonus.c */
char	*check_line(char *line, t_map *map);
/* map_parsing_bonus.c */
char	*ft_sep_join(char *s1, char *s2, char *sep);
char	**getting_line(char *path, t_map *map);
/* pates_finding_bonus.c */
int		path_finding(t_data *data, t_map *map, char **map_array);
/* player_bonus.c */
void	**load_player(t_data data, void **assets);
void	player_reaction(t_data *data, void **assets, char move);
/* player_movement_bonus.c */
int		ft_hook(int keycode, t_data *data);
int		can_move(t_map *map, int y_diff, int x_diff, t_data *data);
void	move_player(t_data *data, int y_diff, int x_diff, int texture);
/* put_string_bonus.c */
int		put_string(t_data *data);
/* sprite_animation_bonus.c */
void	**load_animation(t_data data, void **assets);
void	animation(t_data data, size_t y, size_t x);

#endif
