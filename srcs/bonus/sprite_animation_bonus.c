/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:29:14 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 19:09:31 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	**load_animation_two(t_data data, void **assets)
{
	t_img	image;

	image = data.img;
	assets[SPRITE_FIVE] = load_image(data, SPRITE_FIVE_PATH);
	if (!assets[SPRITE_FIVE])
		return (clear_images(data, assets, SPRITE_FIVE), NULL);
	assets[SPRITE_SIX] = load_image(data, SPRITE_SIX_PATH);
	if (!assets[SPRITE_SIX])
		return (clear_images(data, assets, SPRITE_SIX), NULL);
	assets[SPRITE_SEVEN] = load_image(data, SPRITE_SEVEN_PATH);
	if (!assets[SPRITE_SEVEN])
		return (clear_images(data, assets, SPRITE_SEVEN), NULL);
	assets = load_enemy(data, assets);
	if (!assets)
		return (NULL);
	return (assets);
}

void	**load_animation(t_data data, void **assets)
{
	t_img	image;

	image = data.img;
	assets[SPRITE_DEFAULT] = load_image(data, SPRITE_DEFAULT_PATH);
	if (!assets[SPRITE_DEFAULT])
		return (clear_images(data, assets, SPRITE_DEFAULT), NULL);
	assets[SPRITE_INIT] = load_image(data, SPRITE_INIT_PATH);
	if (!assets[SPRITE_INIT])
		return (clear_images(data, assets, SPRITE_INIT), NULL);
	assets[SPRITE_ONE] = load_image(data, SPRITE_ONE_PATH);
	if (!assets[SPRITE_ONE])
		return (clear_images(data, assets, SPRITE_ONE), NULL);
	assets[SPRITE_TWO] = load_image(data, SPRITE_TWO_PATH);
	if (!assets[SPRITE_TWO])
		return (clear_images(data, assets, SPRITE_TWO), NULL);
	assets[SPRITE_THREE] = load_image(data, SPRITE_THREE_PATH);
	if (!assets[SPRITE_THREE])
		return (clear_images(data, assets, SPRITE_THREE), NULL);
	assets[SPRITE_FOUR] = load_image(data, SPRITE_FOUR_PATH);
	if (!assets[SPRITE_FOUR])
		return (clear_images(data, assets, SPRITE_FOUR), NULL);
	assets = load_animation_two(data, assets);
	if (!assets)
		return (NULL);
	return (assets);
}

static void	put_sleep(t_data data, void *image, size_t y, size_t x)
{
	size_t	i;

	i = 0;
	put_image(data, image, y, x);
	usleep(100000);
}

static void	loop_animation(t_data data, void **assets, size_t y, size_t x)
{
	size_t	loop;

	loop = 15;
	while (--loop)
	{
		put_sleep(data, assets[SPRITE_ONE], y, x);
		put_sleep(data, assets[SPRITE_TWO], y, x);
		put_sleep(data, assets[SPRITE_THREE], y, x);
		put_sleep(data, assets[SPRITE_FOUR], y, x);
		put_sleep(data, assets[SPRITE_FIVE], y, x);
		put_sleep(data, assets[SPRITE_SIX], y, x);
		put_sleep(data, assets[SPRITE_SEVEN], y, x);
		put_sleep(data, assets[SPRITE_SIX], y, x);
		put_sleep(data, assets[SPRITE_FIVE], y, x);
		put_sleep(data, assets[SPRITE_FOUR], y, x);
		put_sleep(data, assets[SPRITE_THREE], y, x);
		put_sleep(data, assets[SPRITE_TWO], y, x);
	}
}

void	animation(t_data data, size_t y, size_t x)
{
	void	**assets;

	assets = data.assets;
	put_sleep(data, assets[SPRITE_DEFAULT], y, x);
	put_sleep(data, assets[SPRITE_INIT], y, x);
	put_sleep(data, assets[SPRITE_FOUR], y, x);
	put_sleep(data, assets[SPRITE_THREE], y, x);
	put_sleep(data, assets[SPRITE_TWO], y, x);
	loop_animation(data, assets, y, x);
	put_sleep(data, assets[SPRITE_TWO], y, x);
	put_sleep(data, assets[SPRITE_THREE], y, x);
	put_sleep(data, assets[SPRITE_FOUR], y, x);
	put_sleep(data, assets[SPRITE_INIT], y, x);
	put_sleep(data, assets[SPRITE_DEFAULT], y, x);
}

/*
	Here we load and put the character win animation to screen
*/
