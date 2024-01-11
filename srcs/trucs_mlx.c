/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trucs_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:01:23 by acroue            #+#    #+#             */
/*   Updated: 2024/01/11 16:19:41 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	t_img	image;
	size_t	x;
	size_t	y;

	x = x_axis * TILE_SIZE;
	y = y_axis * TILE_SIZE;
	data.img.size = TILE_SIZE;
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, mlx_img, x, y);
	return (0);
}

void	**load_images(t_data data)
{
	size_t	i;
	t_img	image;
	void	**assets;
	int		size;

	i = 0;
	assets = malloc((ASSETS) * sizeof(void *));
	if(!assets)
		return (NULL);
	size = TILE_SIZE;
	image = data.img;
	image.addr = "textures/default_texture.xpm";
	assets[0] = mlx_xpm_file_to_image(data.mlx_ptr, image.addr, &size, &size);
	image.addr = "textures/wall.xpm";
	assets[1] = mlx_xpm_file_to_image(data.mlx_ptr, image.addr, &size, &size);
	image.addr = "textures/floor.xpm";
	assets[2] = mlx_xpm_file_to_image(data.mlx_ptr, image.addr, &size, &size);
	image.addr = "textures/exit.xpm";
	assets[3] = mlx_xpm_file_to_image(data.mlx_ptr, image.addr, &size, &size);
	image.addr = "textures/player.xpm";
	assets[4] = mlx_xpm_file_to_image(data.mlx_ptr, image.addr, &size, &size);
	// put_image(data, assets[0], 0, 0);	put_image(data, assets[1], 0, 1);	put_image(data, assets[1], 0, 2);
	// put_image(data, assets[2], 1, 0);	put_image(data, assets[2], 1, 1);	put_image(data, assets[2], 1, 2);
	// put_image(data, assets[2], 2, 0);	put_image(data, assets[2], 2, 1);	put_image(data, assets[2], 2, 2);
	// put_image(data, assets[4], 2, 0);
	// put_image(data, assets[3], 2, 2);
	return (assets);
}

void	clear_images(t_data data, void **assets)
{
	size_t	i;

	i = 0;
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	while (i < ASSETS)
	{
		mlx_destroy_image(data.mlx_ptr, assets[i]);
		i++;
	}
	free(assets);
}

int	main(void)
{
	t_data	data;
	void	**assets;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, MAX_WIDTH * TILE_SIZE, MAX_HEIGHT * TILE_SIZE, "so_long");
	if (!data.win_ptr)
		return (free(data.win_ptr), 0);
	assets = load_images(data);
	sleep(1);
	// mlx_hook(data.win_ptr, 3, 1L<<1, ft_close, &data);
	mlx_key_hook(data.win_ptr, ft_close, &data);
	mlx_loop(data.mlx_ptr);
	clear_images(data, assets);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}