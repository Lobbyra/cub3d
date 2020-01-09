/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:59:54 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/01/09 13:29:06 by jecaudal         ###   ########.fr       */
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
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "l_libc.h"

/* ### Options ### */
# define MOVE_SPEED 1.1
# define ROTATION_SPEED 1.1
# define FOV 90

/* Line types readed binary operators */
# define FLAG_PATH_NORTH 1
# define FLAG_PATH_SOUTH 2
# define FLAG_PATH_EAST 4
# define FLAG_PATH_WEST 8
# define FLAG_PATH_SPRITE 16
# define FLAG_RESOLUTION 32
# define FLAG_COLOR_FLOOR 64
# define FLAG_COLOR_CEILING 128
# define FLAG_MAP 256
# define FLAG_EMPTY 512
# define FLAG_UNKNOW 1024

/* ### ERROR MESSAGES ### */
/* header error messages */
# define ERR_HEAD_MISS "Informations is missing in header"
# define ERR_HEAD_UNKNO "Your header contain unknow informations"
# define ERR_HEAD_RESOL "Your resolution is not valid"
# define ERR_HEAD_FCOLR "Your floor color is not valid"
# define ERR_HEAD_CCOLR "Your ceiling color is not valid"

/* Map error messages */
# define ERR_MAP_WALLS "Your map is not surrounded by walls"
# define ERR_MAP_UNKNO "Your map contain unknow value"
# define ERR_MAP_FORMAT "Your map is not well formated"

typedef int t_err;

typedef struct 		s_file
{
	int				fd;
	char			*raw_res;
	char			*raw_n_path;
	char			*raw_s_path;
	char			*raw_e_path;
	char			*raw_w_path;
	char			*raw_sprite_path;
	char			*raw_map;
	int				curr_line;
	char			player_orientation;
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

/* ### Parsing Declarations ### */
int		header_miner_color(char *rgb);
int		*header_miner_res(char *raw_res);
char	*header_miner_paths(char *raw_paths);


#endif
