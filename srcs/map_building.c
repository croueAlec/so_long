/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:17:20 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 13:35:15 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_fake_rand(void)
{
	int		fd;
	char	buf[1];

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0 || read(fd, buf, 1) < 0)
		return ((void)close(fd), -1);
	close(fd);
	return (buf[0]);
}

int	put_image(t_data data, void *mlx_img, size_t y_axis, size_t x_axis)
{
	size_t	x;
	size_t	y;

	x = x_axis * TILE_SIZE;
	y = y_axis * TILE_SIZE;
	data.img.size = TILE_SIZE;
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, mlx_img, x, y);
	return (0);
}

void	*select_wall(void **assets, char c)
{
	if (c == U_WALL)
		return (assets[UPPER_WALL]);
	if (c == D_WALL)
		return (assets[LOWER_WALL]);
	if (c == L_WALL)
		return (assets[LEFT_WALL]);
	if (c == R_WALL)
		return (assets[RIGHT_WALL]);
	if (c == A_CORNER)
		return (assets[UPPER_LEFT_WALL]);
	if (c == B_CORNER)
		return (assets[UPPER_RIGHT_WALL]);
	if (c == C_CORNER)
		return (assets[LOWER_LEFT_WALL]);
	if (c == D_CORNER)
		return (assets[LOWER_RIGHT_WALL]);
	return (assets[DEFAULT_TEXTURE]);
}

void	*select_image(void **assets, char c)
{
	int	i;

	if (c == COIN)
		return (assets[COIN_TEXTURE]);
	if (c == WALL)
		return (assets[LONE_WALL]);
	if (c == EXIT)
		return (assets[EXIT_TEXTURE]);
	if (c == PLAYER)
		return (assets[PLAYER_TEXTURE]);
	if (c == U_WALL || c == D_WALL || c == L_WALL || c == R_WALL)
		return (select_wall(assets, c));
	if (c == A_CORNER || c == B_CORNER || c == C_CORNER || c == D_CORNER)
		return (select_wall(assets, c));
	i = ft_fake_rand();
	if (c == SPACE && (i % 5 == 0))
		return (assets[TILE_VARIANT]);
	else if (c == SPACE)
		return (assets[TILE]);
	return (assets[DEFAULT_TEXTURE]);
}

void	put_map(t_map *map, t_data data, void **tab)
{
	size_t	y;
	size_t	x;
	char	**map_array;

	map_array = map->map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->length - 1)
		{
			put_image(data, select_image(tab, map_array[y][x]), y + 1, x + 1);
			x++;
		}
		y++;
	}
}
