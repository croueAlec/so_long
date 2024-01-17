/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:01:23 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 10:55:49 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

int	can_move(t_map *map, int y_diff, int x_diff)
{
	char	new_tile;

	new_tile = map->map[map->player_y + y_diff][map->player_x + x_diff];
	if (new_tile == SPACE || new_tile == COIN)
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
		map->map[map->player_y][map->player_x] = exit_texture(data, EXIT);
	else
	{
		put_image(*data, asset[texture], map->player_y + 1, map->player_x + 1);
		map->map[map->player_y][map->player_x] = PLAYER;
	}
	if (map->coins == 0)
		put_image(*data, asset[EXIT_OPEN], data->exit_y + 1, data->exit_x + 1);
}

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

void	put_map(t_map *map, t_data data, void **tab)
{
	size_t	y;
	size_t	x;
	char	**map_array;

	map_array = map->map;
	y = 0;
	while (y < map->height)
	{
		printf("%s\n", map->map[y]);
		x = 0;
		while (x < map->length - 1)
		{
			put_image(data, select_image(tab, map_array[y][x]), y + 1, x + 1);
			x++;
		}
		y++;
	}
}

void	*init_window(t_data data)
{
	void	*win_ptr;
	size_t	width;
	size_t	height;

	width = (data.map->length + 1) * TILE_SIZE;
	height = (data.map->height + 2) * TILE_SIZE;
	win_ptr = mlx_new_window(data.mlx_ptr, width, height, "so_long");
	if (!win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		return (free(data.mlx_ptr), ft_putstr_fd(WIN_FAIL, 2), NULL);
	}
	return (win_ptr);
}

int	rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	put_string(t_data *data)
{
	char	*s1;
	char	*s2;
	void	*mlx;
	size_t	x;
	size_t	y;

	mlx = data->mlx_ptr;
	x = TILE_SIZE * 3;
	y = TILE_SIZE - (TILE_SIZE / 3);
	s1 = ft_itoa(data->steps - 1);
	if (!s1)
		return ;
	s2 = ft_itoa(data->steps);
	mlx_string_put(mlx, data->win_ptr, x / 3, y, rgb(0, 0, 0), STEPS);
	mlx_string_put(mlx, data->win_ptr, x / 3, y, rgb(255, 255, 255), STEPS);
	mlx_string_put(mlx, data->win_ptr, x, y, rgb(0, 0, 0), s1);
	if (s2)
		mlx_string_put(mlx, data->win_ptr, x, y, rgb(255, 255, 255), s2);
	free(s1);
	if (s2)
		free(s2);
}

void	init_data(t_data *data, t_map *map)
{
	data->map = map;
	data->steps = 1;
}

int	manage_window(t_map *map)
{
	t_data	data;
	void	**assets;

	init_data(&data, map);
	if (map->height > MAX_HEIGHT || map->length > MAX_WIDTH)
		return (ft_free(map->map, map->height), ft_err(MAP_TOO_BIG, map), 0);
	if (!path_finding(&data, map, map->map))
		return (ft_free(map->map, map->height), ft_err(MAP_IMPOSSIBLE, map), 0);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (ft_free(map->map, map->height), ft_err(MLX_FAIL, map), 0);
	data.win_ptr = init_window(data);
	if (!data.win_ptr)
		return (0);
	assets = load_assets(data);
	if (!assets)
		return (ft_end(data, assets), ft_putstr_fd(ASSET_FAIL, 2), 0);
	put_map(map, data, assets);
	find_exit(data.map->map, &data);
	data.assets = assets;
	mlx_hook(data.win_ptr, 17, 0, mlx_loop_end, data.mlx_ptr);
	mlx_key_hook(data.win_ptr, ft_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (ft_end(data, assets), 0);
}

// cc test.c libs/minilibx-linux/libmlx.a -lX11 -lXext
