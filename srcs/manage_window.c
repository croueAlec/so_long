/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:01:23 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 13:31:23 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	win_map(t_data *data, int y_diff, int x_diff)
{
	void	**assets;
	t_map	*map;
	size_t	y;
	size_t	x;

	assets = data->assets;
	map = data->map;
	y = map->player_y - y_diff + 1;
	x = map->player_x - x_diff + 1;
	ft_putendl_fd(WIN_MSG, 1);
	mlx_loop_end(data->mlx_ptr);
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
		return (ft_end(data, NULL), ft_putstr_fd(ASSET_FAIL, 2), 0);
	put_map(map, data, assets);
	find_exit(data.map->map, &data);
	data.assets = assets;
	mlx_hook(data.win_ptr, 17, 0, mlx_loop_end, data.mlx_ptr);
	mlx_key_hook(data.win_ptr, ft_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (ft_end(data, assets), 0);
}

/*
	Here we have the functions to create the window
	and handle the core gameplay loop.
*/
