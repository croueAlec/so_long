/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:44:32 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 14:21:25 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	*load_image(t_data data, char *path)
{
	void	*i;
	int		s;

	s = TILE_SIZE;
	i = mlx_xpm_file_to_image(data.mlx_ptr, path, &s, &s);
	if (!i)
	{
		i = mlx_xpm_file_to_image(data.mlx_ptr, DEFAULT_TEXTURE_PATH, &s, &s);
		if (!i)
			return (NULL);
	}
	return (i);
}

void	**load_tiles(t_data data, void **assets)
{
	t_img	image;

	image = data.img;
	assets[TILE] = load_image(data, TILE_PATH);
	if (!assets[TILE])
		return (clear_images(data, assets, TILE), NULL);
	assets[TILE_VARIANT] = load_image(data, TILE_VARIANT_PATH);
	if (!assets[TILE_VARIANT])
		return (clear_images(data, assets, TILE_VARIANT), NULL);
	assets[LONE_WALL] = load_image(data, LONE_WALL_PATH);
	if (!assets[LONE_WALL])
		return (clear_images(data, assets, LONE_WALL), NULL);
	assets[EXIT_OPEN] = load_image(data, EXIT_OPEN_TEXTURE_PATH);
	if (!assets[EXIT_OPEN])
		return (clear_images(data, assets, EXIT_OPEN), NULL);
	assets = load_player(data, assets);
	if (!assets)
		return (NULL);
	return (assets);
}

void	**load_walls(t_data data, void **assets)
{
	t_img	image;

	image = data.img;
	assets[UPPER_WALL] = load_image(data, UPPER_WALL_PATH);
	if (!assets[UPPER_WALL])
		return (clear_images(data, assets, UPPER_WALL), NULL);
	assets[LOWER_WALL] = load_image(data, LOWER_WALL_PATH);
	if (!assets[LOWER_WALL])
		return (clear_images(data, assets, LOWER_WALL), NULL);
	assets[LEFT_WALL] = load_image(data, LEFT_WALL_PATH);
	if (!assets[LEFT_WALL])
		return (clear_images(data, assets, LEFT_WALL), NULL);
	assets[RIGHT_WALL] = load_image(data, RIGHT_WALL_PATH);
	if (!assets[RIGHT_WALL])
		return (clear_images(data, assets, RIGHT_WALL), NULL);
	assets = load_tiles(data, assets);
	if (!assets)
		return (NULL);
	return (assets);
}

void	**load_corners(t_data data, void **assets)
{
	t_img	image;

	image = data.img;
	assets[UPPER_LEFT_WALL] = load_image(data, UPPER_LEFT_WALL_PATH);
	if (!assets[UPPER_LEFT_WALL])
		return (clear_images(data, assets, UPPER_LEFT_WALL), NULL);
	assets[LOWER_LEFT_WALL] = load_image(data, LOWER_LEFT_WALL_PATH);
	if (!assets[LOWER_LEFT_WALL])
		return (clear_images(data, assets, LOWER_LEFT_WALL), NULL);
	assets[UPPER_RIGHT_WALL] = load_image(data, UPPER_RIGHT_WALL_PATH);
	if (!assets[UPPER_RIGHT_WALL])
		return (clear_images(data, assets, UPPER_RIGHT_WALL), NULL);
	assets[LOWER_RIGHT_WALL] = load_image(data, LOWER_RIGHT_WALL_PATH);
	if (!assets[LOWER_RIGHT_WALL])
		return (clear_images(data, assets, LOWER_RIGHT_WALL), NULL);
	assets = load_walls(data, assets);
	if (!assets)
		return (NULL);
	return (assets);
}

void	**load_assets(t_data data)
{
	t_img	image;
	void	**assets;

	assets = malloc((ASSETS + 1) * sizeof(void *));
	if (!assets)
		return (NULL);
	image = data.img;
	assets[DEFAULT_TEXTURE] = load_image(data, DEFAULT_TEXTURE_PATH);
	if (!assets[DEFAULT_TEXTURE])
		return (clear_images(data, assets, DEFAULT_TEXTURE), NULL);
	assets[PLAYER_TEXTURE] = load_image(data, PLAYER_TEXTURE_PATH);
	if (!assets[PLAYER_TEXTURE])
		return (clear_images(data, assets, PLAYER_TEXTURE), NULL);
	assets[EXIT_TEXTURE] = load_image(data, EXIT_TEXTURE_PATH);
	if (!assets[EXIT_TEXTURE])
		return (clear_images(data, assets, EXIT_TEXTURE), NULL);
	assets[COIN_TEXTURE] = load_image(data, COIN_TEXTURE_PATH);
	if (!assets[COIN_TEXTURE])
		return (clear_images(data, assets, COIN_TEXTURE), NULL);
	assets = load_corners(data, assets);
	if (!assets)
		return (NULL);
	return (assets);
}

/*
	Here we load most of our textures.
*/
