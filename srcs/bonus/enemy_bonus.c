/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:37:51 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 19:13:36 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	**load_enemy(t_data data, void **assets)
{
	t_img	image;

	image = data.img;
	assets[ENEMY_DEFAULT] = load_image(data, ENEMY_DEFAULT_PATH);
	if (!assets[ENEMY_DEFAULT])
		return (clear_images(data, assets, ENEMY_DEFAULT), NULL);
	assets[ENEMY_BACK] = load_image(data, ENEMY_BACK_PATH);
	if (!assets[ENEMY_BACK])
		return (clear_images(data, assets, ENEMY_BACK), NULL);
	assets[ENEMY_LEFT] = load_image(data, ENEMY_LEFT_PATH);
	if (!assets[ENEMY_LEFT])
		return (clear_images(data, assets, ENEMY_LEFT), NULL);
	assets[ENEMY_RIGHT] = load_image(data, ENEMY_RIGHT_PATH);
	if (!assets[ENEMY_RIGHT])
		return (clear_images(data, assets, ENEMY_RIGHT), NULL);
	return (assets);
}

void	find_enemy(char **map_array, t_data *data)
{
	size_t	x;
	size_t	y;
	t_map	*map;

	map = data->map;
	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->length - 1)
		{
			if (map_array[y][x] == ENEMY)
				break ;
			x++;
		}
		if (map_array[y][x] == ENEMY)
			break ;
		y++;
	}
	data->map->enemy_y = y;
	data->map->enemy_x = x;
}

int	enemy_can_move(t_map *map, int y_diff, int x_diff)
{
	char	new_tile;

	new_tile = map->map[map->enemy_y + y_diff][map->enemy_x + x_diff];
	if (new_tile == PLAYER || new_tile == EX_PLAYER)
		return (2);
	if (new_tile == SPACE)
		return (1);
	return (0);
}

void	move_enemy(t_data *data, int y_diff, int x_diff, int texture)
{
	void	**asset;
	t_map	*map;

	map = data->map;
	asset = data->assets;
	put_image(*data, asset[TILE], map->enemy_y + 1, map->enemy_x + 1);
	map->map[map->enemy_y][map->enemy_x] = SPACE;
	map->enemy_y += y_diff;
	map->enemy_x += x_diff;
	put_image(*data, asset[texture], map->enemy_y + 1, map->enemy_x + 1);
	map->map[map->enemy_y][map->enemy_x] = ENEMY;
}

void	enemy_pathfind(t_data *data)
{
	if (enemy_can_move(data->map, -1, 0) == 2)
		player_lose(data, data->map);
	else if (enemy_can_move(data->map, 1, 0) == 2)
		player_lose(data, data->map);
	else if (enemy_can_move(data->map, 0, 1) == 2)
		player_lose(data, data->map);
	else if (enemy_can_move(data->map, 0, -1) == 2)
		player_lose(data, data->map);
	else if (enemy_can_move(data->map, -1, 0) && (ft_fake_rand() % 2))
		move_enemy(data, -1, 0, ENEMY_BACK);
	else if (enemy_can_move(data->map, 1, 0) && (ft_fake_rand() % 2))
		move_enemy(data, 1, 0, ENEMY_DEFAULT);
	else if (enemy_can_move(data->map, 0, 1) && (ft_fake_rand() % 2))
		move_enemy(data, 0, 1, ENEMY_RIGHT);
	else if (enemy_can_move(data->map, 0, -1) && (ft_fake_rand() % 2))
		move_enemy(data, 0, -1, ENEMY_LEFT);
}
