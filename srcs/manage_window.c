/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:01:23 by acroue            #+#    #+#             */
/*   Updated: 2024/01/12 19:07:28 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

int	ft_close(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		printf("close");
		mlx_loop_end(data->mlx_ptr);
	}
	else if (keycode == 'w')
	{
		printf("up\n");
	}
	else if (keycode == 's')
	{
		printf("down\n");
	}
	else if (keycode == 'd')
	{
		printf("right\n");
	}
	else if (keycode == 'a')
	{
		printf("left\n");
	}
	return (0);
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

void	clear_images(t_data data, void **assets, size_t size)
{
	size_t	i;

	i = 0;
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	while (i <= size)
	{
		mlx_destroy_image(data.mlx_ptr, assets[i]);
		i++;
	}
	free(assets);
}

int	ft_end(t_data data, void **assets)
{
	clear_images(data, assets, ASSETS);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
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

int	ft_fake_rand(void)
{
	int		fd;
	char	buf[1];

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0 || read(fd, buf, 1) < 0)
		return ((void)close(fd), -1);
	close(fd);
	return (buf[0]);
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

void	put_map(t_map *map, t_data data, void **assets)
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
			put_image(data, select_image(assets, map_array[y][x]), y, x);
			x++;
		}
		y++;
	}
}

int	manage_window(t_map *map) // gerer les tailles max de cartes
{
	t_data	data;
	void	**assets;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, MAX_WIDTH * TILE_SIZE, MAX_HEIGHT * TILE_SIZE, "so_long");
	if (!data.win_ptr)
		return (free(data.win_ptr), 0);
	assets = load_assets(data);
	if (!assets)
		return (ft_end(data, assets), 0);
	put_map(map, data, assets);
	// mlx_hook(data.win_ptr, 3, 1L<<1, ft_close, &data);
	mlx_key_hook(data.win_ptr, ft_close, &data);
	mlx_loop(data.mlx_ptr);
	return (ft_end(data, assets), 0);
}

// cc test.c libs/minilibx-linux/libmlx.a -lX11 -lXext
