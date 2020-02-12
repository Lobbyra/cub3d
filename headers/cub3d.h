/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:59:54 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/02/12 17:07:12 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libc_lobb/headers/l_libc.h"

/*
** ### Options ###
*/

# define CUB_FOV 66
# define CUB_RSPEED 0.06
# define CUB_MSPEED 0.06
# define BUFFER_SIZE 100
# define CUB_BPP 32

# define WIDTH_SCREEN 2560
# define HEIGHT_SCREEN 1440

/*
** Colors
*/

# define HORIZONTAL 0
# define VERTICAL 1
# define COLOR_W 16777215
# define COLOR_NORTH 12727830
# define COLOR_SOUTH 38886
# define COLOR_EAST 4504882
# define COLOR_WEST 16500017

/*
** Line type sig
*/
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

/*
** ### ERROR MESSAGES ###
*/

/*
** Global err sig
*/
# define ERR_MEMALLOC 10
# define ERR_UNKNOW 20
# define ERR_ERRNO 30
# define ERR_NOT_CUB 40
# define ERR_MISSING 50
# define ERR_DUPED_INFO 60

/*
** MAP err sig
*/
# define ERR_MAP_HOLE 10
# define ERR_MAP_PLAYDUP 20
# define ERR_MAP_PLAY404 30
# define ERR_MAP_MEMALLOC 40

/*
** COLOR err sig
*/
# define ERR_COLOR_FORMAT 10
# define ERR_COLOR_VALUE 20

/*
** RESOLUTION err sig
*/
# define ERR_RESOLUTION_FORMAT 10
# define ERR_RESOLUTION_VAL_X 20
# define ERR_RESOLUTION_VAL_Y 30

/*
** header error messages
*/
# define ERR_MSG_HEAD_MISS "Information(s) is missing in header.\n"
# define ERR_MSG_HEAD_UNKNO "This line contain unknow information.\n"
# define ERR_MSG_NOT_CUB "This program can't take other file than *.cub.\n"
# define ERR_MSG_MALLOC "Memory allocation error encountered.\n"
# define ERR_MSG_DUPED "Same informations type is duplicated in your file.\n"

# define ERR_MSG_CLR_FORMAT "The correct format is [C ]|[F ][R],[G],[B].\n"
# define ERR_MSG_CLR_VALUE "The value of each color must be between 0 and 255.\n"

# define ERR_MSG_RES_FORMAT "The correct format is [R ][x][' '][y].\n"
# define ERR_MSG_RES_VALUE_X "The value of x must be higher than 0.\n"
# define ERR_MSG_RES_VALUE_Y "The value of y must be higher than 0.\n"

/*
** Map error messages
*/
# define ERR_MSG_MAP_HOLE "Your map is not surrounded by walls.\n"
# define ERR_MSG_MAP_PLAY404 "Player not found."
# define ERR_MSG_MAP_PLAYDUP "Your map contain two players or more.\n"

/*
** KEYS
*/

# define KEY_Z 13
# define KEY_S 1
# define KEY_Q 0
# define KEY_D 2
# define KEY_ALT 261
# define KEY_ESCAPE 53
# define KEY_ESCAPE 53
# define KEY_ARRR 124
# define KEY_ARRL 123

# define KEY_UP 1
# define KEY_DOWN 2
# define KEY_RIGHT 4
# define KEY_LEFT 8
# define KEY_DEBUG 16
# define KEY_ROTR 32
# define KEY_ROTL 64

typedef int t_err;
typedef int t_sig;


typedef struct 	s_file
{
	int			fd;
	char		*raw_res;
	char		*raw_n_path;
	char		*raw_s_path;
	char		*raw_e_path;
	char		*raw_w_path;
	char		*raw_sprite_path;
	char		*raw_floor_color;
	char		*raw_ceiling_color;
	char		*raw_map;
	int			curr_line;
}				t_file;

typedef struct 	s_info
{
	int			res_x;
	int			res_y;
	char		*n_path;
	char		*s_path;
	char		*e_path;
	char		*w_path;
	char		*sprite_path;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	char		player_orientation;
}				t_info;

typedef struct	s_img
{
	int			width;
	int			height;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_img;

typedef struct	s_stock
{
	int			w;
	int			h;
	int			fov;
	t_img		*img;
	char		**map;
	char		*n_path;
	char		*s_path;
	char		*e_path;
	char		*w_path;
	void		*mlx_ptr;
	void		*win_ptr;
	double		movspeed;
	int			floor_color;
	char		*sprite_path;
	int			ceiling_color;
	double		rotspeed;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	t_bool		is_debug;
	int			key;
	int			x;
	int			stepx;
	int			stepy;
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			side;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	char		side_hited;
}				t_stock;

/*
** ### Debug Declarations ###
*/
void	print_t_sig(t_sig sig);
void	print_t_err(t_err err);
void	print_t_file(t_file *file);
void	print_t_info(t_info *info);

/*
** ### Parsing Declarations ###
*/
/*
** FILE
*/
/*
** get
*/
t_bool	is_map(char c);
t_file	*init_file(void);
int		get_map(t_file *file);
t_sig	detect_line(char *str);
void	free_file(t_file *file);
t_bool	get_file(t_file *file, char *path);
t_bool	print_err_file(int curr_line, t_err err);
/*
** Parsing
*/
t_info	*parsing(char *path);
t_bool	parsing_file(t_file *file);
t_bool	parsing_map(char *map, int curr_line);
t_bool	curr_line_len_isok(char *prev, char *curr);
int		last_empty(char *line);
t_bool	border_isok(char *line);
int		how_many_players(char *line);
t_bool	map_print_err(t_err err, int curr_line, char **arr);
t_bool	parsing_path(char *path);
t_bool	parsing_color(char *color);
t_bool	parsing_resolution(char *resolution);

/*
** Info
*/
int		color_miner(char *rgb);
int		*resolution_miner(char *raw_res);
char	*path_miner(char *raw_paths);
t_info	*init_info(void);
void	free_info(t_info *info);
t_info	*get_info(t_file *file);

/*
** Stock
*/

int		cub_exit(void *param);
t_stock	*init_stock(t_info *info);
double	init_stock_find_dirx(char player_orientation);
double	init_stock_find_diry(char player_orientation);
double	init_stock_find_planex(char player_orientation);
double	init_stock_find_planey(char player_orientation);
void	free_stock(t_stock *stock);
void	raycasting(t_stock *stock);
void	print_t_stock(t_stock *stock);
int		key_pressed(int keycode, void *param);
int		key_released(int keycode, void *param);

/*
** Render
*/

int		render(void *param);
void	lmlx_push_img(t_img *img);
void	player_update(t_stock *s);
void	lmlx_destroy_image(t_img *img);
void	perform_raycasting(t_stock *stock);
void	lmlx_pixel_put(t_img *img, int rgb, int x, int y);
void	draw_vert_line(t_stock *stock, int y_start, int y_end);
char	cub_side_hited(double raydirx, double raydiry, int side);
t_img	*lmlx_new_image(void *mlx_ptr, void *win_ptr, int width, int height);


#endif
