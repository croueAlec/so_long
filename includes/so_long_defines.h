/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_defines.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:54:38 by acroue            #+#    #+#             */
/*   Updated: 2024/01/11 15:59:38 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINES_H
# define SO_LONG_DEFINES_H

/* Map parameters */
# define WALL '1'
# define SPACE '0'
# define COIN 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define MAX_WIDTH 30
# define MAX_HEIGHT 16

/* Textures */
# define ASSETS 5
# define TILE_SIZE 32

/* Error messages */
# define BAD_MAP_PATH "Bad map path"
# define MAP_NOT_RECT "Map is not a rectangle"
# define MISSING_COIN "Not enough coins"
# define MISSING_EXIT "No exit"
# define MISSING_SPAWN_POINT "No player spawn point"
# define DUPLICATE_EXIT "Too many exits"
# define DUPLICATE_SPAWN_POINT "Too many player spawn points"
# define WRONG_MAP_CHAR "Unrecognized character in map file"
# define BORDER_ERROR "Map is not completely closed"

# define ESCAPE 65307

#endif
