/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:46:58 by acroue            #+#    #+#             */
/*   Updated: 2024/01/16 13:34:12 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	**load_player(t_data data, void **assets)
{
	t_img	image;

	image = data.img;
	assets[PLAYER_BACK] = load_image(data, PLAYER_BACK_PATH);
	if (!assets[PLAYER_BACK])
		return (clear_images(data, assets, PLAYER_BACK), NULL);
	assets[PLAYER_LEFT] = load_image(data, PLAYER_LEFT_PATH);
	if (!assets[PLAYER_LEFT])
		return (clear_images(data, assets, PLAYER_LEFT), NULL);
	assets[PLAYER_RIGHT] = load_image(data, PLAYER_RIGHT_PATH);
	if (!assets[PLAYER_RIGHT])
		return (clear_images(data, assets, PLAYER_RIGHT), NULL);
	return (assets);
}


void	player_reaction(t_data *d, void **a, char move)
{
	t_map	*map;

	map = d->map;
	if (move == UP)
		put_image(*d, a[PLAYER_BACK], map->player_y + 1, map->player_x + 1);
	if (move == DOWN)
		put_image(*d, a[PLAYER_TEXTURE], map->player_y + 1, map->player_x + 1);
	if (move == LEFT)
		put_image(*d, a[PLAYER_LEFT], map->player_y + 1, map->player_x + 1);
	if (move == RIGHT)
		put_image(*d, a[PLAYER_RIGHT], map->player_y + 1, map->player_x + 1);
	if (move == UP && can_move(d->map, -1, 0))
		move_player(d, -1, 0);
	if (move == DOWN && can_move(d->map, 1, 0))
		move_player(d, 1, 0);
	if (move == RIGHT && can_move(d->map, 0, 1))
		move_player(d, 0, 1);
	if (move == LEFT && can_move(d->map, 0, -1))
		move_player(d, 0, -1);
}
