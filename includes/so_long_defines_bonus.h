/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_defines_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:54:38 by acroue            #+#    #+#             */
/*   Updated: 2024/01/17 15:25:15 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINES_BONUS_H
# define SO_LONG_DEFINES_BONUS_H

/* Map parameters */
# define WALL '1'
# define SPACE '0'
# define COIN 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define EX_PLAYER 'e'
# define MAX_WIDTH 60
# define MAX_HEIGHT 32
# define U_WALL 'U'
# define D_WALL 'D'
# define L_WALL 'L'
# define R_WALL 'R'
# define A_CORNER 'a'
# define B_CORNER 'b'
# define C_CORNER 'c'
# define D_CORNER 'd'

/* Textures */
# define TILE_SIZE 32
# define ASSETS 27
# define DEFAULT_TEXTURE 0
# define PLAYER_TEXTURE 1
# define EXIT_TEXTURE 2
# define COIN_TEXTURE 3
# define UPPER_LEFT_WALL 4
# define LOWER_LEFT_WALL 5
# define UPPER_RIGHT_WALL 6
# define LOWER_RIGHT_WALL 7
# define UPPER_WALL 8
# define LOWER_WALL 9
# define LEFT_WALL 10
# define RIGHT_WALL 11
# define TILE 12
# define TILE_VARIANT 13
# define LONE_WALL 14
# define EXIT_OPEN 15
# define PLAYER_BACK 16
# define PLAYER_LEFT 17
# define PLAYER_RIGHT 18
# define SPRITE_DEFAULT 19
# define SPRITE_INIT 20
# define SPRITE_ONE 21
# define SPRITE_TWO 22
# define SPRITE_THREE 23
# define SPRITE_FOUR 24
# define SPRITE_FIVE 25
# define SPRITE_SIX 26
# define SPRITE_SEVEN 27

/* Texture paths */
# define DEFAULT_TEXTURE_PATH "textures/default_texture.xpm"
# define PLAYER_TEXTURE_PATH "textures/player_default.xpm"
# define EXIT_TEXTURE_PATH "textures/exit_closed.xpm"
# define COIN_TEXTURE_PATH "textures/coin.xpm"
# define UPPER_LEFT_WALL_PATH "textures/upper_left_wall.xpm"
# define LOWER_LEFT_WALL_PATH "textures/lower_left_wall.xpm"
# define UPPER_RIGHT_WALL_PATH "textures/upper_right_wall.xpm"
# define LOWER_RIGHT_WALL_PATH "textures/lower_right_wall.xpm"
# define UPPER_WALL_PATH "textures/upper_wall.xpm"
# define LOWER_WALL_PATH "textures/lower_wall.xpm"
# define LEFT_WALL_PATH "textures/left_wall.xpm"
# define RIGHT_WALL_PATH "textures/right_wall.xpm"
# define TILE_PATH "textures/tile.xpm"
# define TILE_VARIANT_PATH "textures/tile_variant.xpm"
# define LONE_WALL_PATH "textures/lone_wall.xpm"
# define EXIT_OPEN_TEXTURE_PATH "textures/exit_open.xpm"
# define PLAYER_BACK_PATH "textures/player_back.xpm"
# define PLAYER_LEFT_PATH "textures/player_left.xpm"
# define PLAYER_RIGHT_PATH "textures/player_right.xpm"
# define SPRITE_DEFAULT_PATH "textures/sprite_default.xpm"
# define SPRITE_INIT_PATH "textures/sprite_init.xpm"
# define SPRITE_ONE_PATH "textures/sprite_one.xpm"
# define SPRITE_TWO_PATH "textures/sprite_two.xpm"
# define SPRITE_THREE_PATH "textures/sprite_three.xpm"
# define SPRITE_FOUR_PATH "textures/sprite_four.xpm"
# define SPRITE_FIVE_PATH "textures/sprite_five.xpm"
# define SPRITE_SIX_PATH "textures/sprite_six.xpm"
# define SPRITE_SEVEN_PATH "textures/sprite_seven.xpm"

/* Messages */
# define BAD_MAP_PATH "Bad map path"
# define MAP_TOO_BIG "Map is too large, it must be  at most 60x32"
# define MAP_IMPOSSIBLE "Map can't be solved"
# define MLX_FAIL "Failed to init MLX"
# define WIN_FAIL "Failed to init Window"
# define ASSET_FAIL "Failed to load assets"
# define MAP_NOT_RECT "Map is not a rectangle"
# define MISSING_COIN "Not enough coins"
# define MISSING_EXIT "No exit"
# define MISSING_SPAWN_POINT "No player spawn point"
# define DUPLICATE_EXIT "Too many exits"
# define DUPLICATE_SPAWN_POINT "Too many player spawn points"
# define WRONG_MAP_CHAR "Unrecognized character in map file"
# define BORDER_ERROR "Map is not completely closed"
# define MALLOC_ERR "A malloc failed"
# define WIN_MSG "You win ! Thanks for playing"
# define STEPS "Steps"

/* Controls */
# define ESCAPE 65307
# define UP 'w'
# define LEFT 'a'
# define DOWN 's'
# define RIGHT 'd'

#endif
