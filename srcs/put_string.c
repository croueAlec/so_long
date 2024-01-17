/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:45:03 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 13:11:12 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	put_string(t_data *data)
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
	s2 = ft_itoa(data->steps);
	if (!s1 || !s2)
	{
		free(s1);
		free(s2);
		ft_free(data->map->map, data->map->height);
		return (ft_end(*data, data->assets), ft_err(MALLOC_ERR, data->map), 0);
	}
	mlx_string_put(mlx, data->win_ptr, x / 3, y, rgb(0, 0, 0), STEPS);
	mlx_string_put(mlx, data->win_ptr, x / 3, y, rgb(255, 255, 255), STEPS);
	mlx_string_put(mlx, data->win_ptr, x, y, rgb(0, 0, 0), s1);
	mlx_string_put(mlx, data->win_ptr, x, y, rgb(255, 255, 255), s2);
	ft_printf("%d step(s)\n", data->steps++);
	return (free(s1), free(s2), 0);
}

/*
	Here we have all the functions relevant to putting the string on the screen
*/
