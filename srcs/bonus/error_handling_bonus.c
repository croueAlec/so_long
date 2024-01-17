/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:27:05 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 14:19:31 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_err(char *error, void *ptr)
{
	if (ptr)
		free(ptr);
	ft_putstr_fd(error, 2);
	exit(0);
}

void	clear_images(t_data data, void **assets, size_t size)
{
	size_t	i;

	i = 0;
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	while (i <= size && size != 0)
	{
		mlx_destroy_image(data.mlx_ptr, assets[i]);
		i++;
	}
	free(assets);
}

int	ft_end(t_data data, void **assets)
{
	if (assets)
		clear_images(data, assets, ASSETS);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

/*
	Here we have the functions we use when we want to close the game
*/
