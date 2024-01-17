/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:14:05 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 13:25:13 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		mlx_loop_end(data->mlx_ptr);
	else if (keycode == UP)
		player_reaction(data, data->assets, UP);
	else if (keycode == DOWN)
		player_reaction(data, data->assets, DOWN);
	else if (keycode == RIGHT)
		player_reaction(data, data->assets, RIGHT);
	else if (keycode == LEFT)
		player_reaction(data, data->assets, LEFT);
	return (0);
}

int	can_move(t_map *map, int y_diff, int x_diff, t_data *data)
{
	char	new_tile;

	new_tile = map->map[map->player_y + y_diff][map->player_x + x_diff];
	if (new_tile == SPACE || new_tile == COIN)
		return (1);
	if (new_tile == EXIT && data->map->coins == 0)
		return (1);
	return (0);
}

char	exit_texture(t_data *data, char tile)
{
	void	**assets;
	t_map	*map;
	size_t	y;
	size_t	x;

	map = data->map;
	x = map->player_x + 1;
	y = map->player_y + 1;
	assets = data->assets;
	if (map->coins == 0)
	{
		ft_free(map->map, map->height);
		ft_end(*data, data->assets);
		ft_err(WIN_MSG, map);
	}
	if (tile == EX_PLAYER)
	{
		put_image(*data, assets[EXIT_TEXTURE], y, x);
		return (EXIT);
	}
	else
	{
		put_image(*data, assets[DEFAULT_TEXTURE], y, x);
		return (EX_PLAYER);
	}
}

void	move_player(t_data *data, int y_diff, int x_diff, int texture)
{
	void	**asset;
	t_map	*map;

	map = data->map;
	asset = data->assets;
	if (map->map[map->player_y][map->player_x] == EX_PLAYER)
		map->map[map->player_y][map->player_x] = exit_texture(data, EX_PLAYER);
	else
	{
		put_image(*data, asset[TILE], map->player_y + 1, map->player_x + 1);
		map->map[map->player_y][map->player_x] = SPACE;
	}
	map->player_y += y_diff;
	map->player_x += x_diff;
	if (map->map[map->player_y][map->player_x] == COIN)
		map->coins--;
	if (map->map[map->player_y][map->player_x] == EXIT)
		win_map(data, y_diff, x_diff);
	else
	{
		put_image(*data, asset[texture], map->player_y + 1, map->player_x + 1);
		map->map[map->player_y][map->player_x] = PLAYER;
	}
	if (map->coins == 0)
		put_image(*data, asset[EXIT_OPEN], data->exit_y + 1, data->exit_x + 1);
}
/*
	If you want to make the exit texture walkable use
		map->map[map->player_y][map->player_x] = exit_texture(data, EXIT);
	instead of
		win_map(data, y_diff, x_diff);
	and in can_move remove
	 && data->map->coins == 0
 */
/*
	Here we make sure that the tile the player tries to go to he can,
	if he can we move him here we do, if he can't we just turn him
*/
