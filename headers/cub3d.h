/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:59:54 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/01/20 12:59:15 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Colors
**
**0000000000000000000000000000000
**0000000BBBBBBBBGGGGGGGGRRRRRRRR
*/

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <errno.h>
#include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "../libc_lobb/headers/l_libc.h"

/* ### Options ### */
# define MOVE_SPEED 1.1
# define ROTATION_SPEED 1.1
# define FOV 90
# define BUFFER_SIZE 100

/* Line type sig */
# define LSIG_EMPTY 1
# define LSIG_RESOLUTION 2
# define LSIG_NPATH 4
# define LSIG_SPATH 8
# define LSIG_EPATH 16
# define LSIG_WPATH 32
# define LSIG_SPRITE_PATH 64
# define LSIG_FLOOR_CLR 128
# define LSIG_CEILING_CLR 256
# define LSIG_MAP 512
# define LSIG_UNKNOW 1024
# define LSIG_NULL 2048
# define LSIG_COMPLETE 4096

/* ### ERROR MESSAGES ### */

/* Global err sig*/
# define ERR_MEMALLOC 10
# define ERR_UNKNOW 20
# define ERR_ERRNO 30
# define ERR_NOT_CUB 40
# define ERR_MISSING 50
# define ERR_DUPED_INFO 60

/* MAP err sig*/
# define ERR_MAP_HOLE 10
# define ERR_MAP_PLAYDUP 20
# define ERR_MAP_PLAY404 30
# define ERR_MAP_MEMALLOC 40

/* COLOR err sig*/
# define ERR_COLOR_FORMAT 10
# define ERR_COLOR_VALUE 20

/* RESOLUTION err sig*/
# define ERR_RESOLUTION_FORMAT 10
# define ERR_RESOLUTION_VAL_X 20
# define ERR_RESOLUTION_VAL_Y 30

/* header error messages */
# define ERR_MSG_HEAD_MISS "Information(s) is missing in header.\n"
# define ERR_MSG_HEAD_UNKNO "This line contain unknow information.\n"
# define ERR_MSG_NOT_CUB "This program can't take other file than .cub.\n"
# define ERR_MSG_MALLOC "Memory allocation error encountered.\n"
# define ERR_MSG_DUPED "Same informations type is duplicated in your file.\n"

# define ERR_MSG_CLR_FORMAT "The correct format is [C ]|[F ][R],[G],[B].\n"
# define ERR_MSG_CLR_VALUE "The value of each color must be between 0 and 255.\n"

# define ERR_MSG_RES_FORMAT "The correct format is [R ][x][' '][y].\n"
# define ERR_MSG_RES_VALUE_X "The value of x must be higher than 0.\n"
# define ERR_MSG_RES_VALUE_Y "The value of y must be higher than 0.\n"

/* Map error messages */
# define ERR_MSG_MAP_HOLE "Your map is not surrounded by walls.\n"
# define ERR_MSG_MAP_PLAY404 "Player not found."
# define ERR_MSG_MAP_PLAYDUP "Your map contain two players or more.\n"

typedef int t_err;
typedef int t_sig;


typedef struct 		s_file
{
	int				fd;
	char			*raw_res;
	char			*raw_n_path;
	char			*raw_s_path;
	char			*raw_e_path;
	char			*raw_w_path;
	char			*raw_sprite_path;
	char			*raw_floor_color;
	char			*raw_ceiling_color;
	char			*raw_map;
	int				curr_line;
}					t_file;

typedef struct 		s_info
{
	int				res_x;
	int				res_y;
	char			*n_path;
	char			*s_path;
	char			*e_path;
	char			*w_path;
	char			*sprite_path;
	int				floor_color;
	int				ceiling_color;
	char			**map;
	char			player_orientation;
}					t_info;
/*
** orientation is in degrese, 0 is oriented to east.
** Is initialized accord to the data read on the map.
*/
typedef struct 	s_player
{
	float		pos_x;
	float		pos_y;
	float		orientation;
	float		move_speed;
	float		rotation_speed;
}				t_player;

/* ### Debug Declarations ### */
void	print_t_sig(t_sig sig);
void	print_t_err(t_err err);
void	print_t_file(t_file *file);
void	print_t_info(t_info *info);

/* ### Parsing Declarations ### */
/* Global */
t_sig	detect_line(char *str);
t_bool	is_map(char c);

/* File */
t_sig	get_file(t_file *file, char *path);
t_err	print_err_file(int curr_line, t_err err);
t_file	*init_file(void);
void	free_file(t_file *file);
int		get_map(t_file *file);
t_bool	parsing_map(char *map, int curr_line);
t_bool	parsing_color(char *color, int curr_line);
t_bool	parsing_resolution(char *resolution, int curr_line);

/* Info */
int		header_miner_color(char *rgb);
int		*header_miner_res(char *raw_res);
char	*header_miner_paths(char *raw_paths);
t_info	*init_info(void);
void	free_info(t_info *info);



#endif
