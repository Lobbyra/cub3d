/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:59:54 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/02/21 11:57:02 by jecaudal         ###   ########.fr       */
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
# include "data_structures.h"
# include "error_messages.h"

/*
** ### Options ###
*/
# define CUB_RSPEED 0.06
# define CUB_MSPEED 0.06
# define BUFFER_SIZE 100

# define WIDTH_SCREEN 2560
# define HEIGHT_SCREEN 1440
# define WALL_HEIGHT_PROTECTION 200000

/*
** Colors
*/
# define COLOR_BLUE 4876733
# define COLOR_GREEN 7921807
# define COLOR_RED 15412998
# define COLOR_YELLOW 16169275

# define HORIZONTAL 0
# define VERTICAL 0
# define COLOR_W 16777215
# define COLOR_NORTH COLOR_BLUE
# define COLOR_SOUTH COLOR_RED
# define COLOR_EAST COLOR_GREEN
# define COLOR_WEST COLOR_YELLOW
# define COLOR_ERR COLOR_W

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

typedef int		t_err;
typedef int		t_sig;

/*
** ### Debug Declarations ###
*/
void			print_t_sig(t_sig sig);
void			print_t_err(t_err err);
void			print_t_file(t_file *file);
void			print_t_info(t_info *info);

/*
** ### Parsing Declarations ###
*/
/*
** get
*/
t_bool			is_map(char c);
t_file			*init_file(void);
int				get_map(t_file *file);
t_sig			detect_line(char *str);
void			free_file(t_file *file);
t_bool			get_file(t_file *file, char *path);
t_bool			print_err_file(int curr_line, t_err err);

/*
** Parsing
*/
t_info			*parsing(char *path);
t_bool			parsing_file(t_file *file);
t_bool			parsing_map(char *map, int curr_line);
t_bool			curr_line_len_isok(char *prev, char *curr);
int				last_empty(char *line);
t_bool			border_isok(char *line);
int				how_many_players(char *line);
t_bool			map_print_err(t_err err, int curr_line, char **arr);
t_bool			parsing_path(char *path);
t_bool			parsing_color(char *color);
t_bool			parsing_resolution(char *resolution);

/*
** Info
*/
int				color_miner(char *rgb);
int				*resolution_miner(char *raw_res);
char			*path_miner(char *raw_paths);
t_info			*init_info(void);
void			free_info(t_info *info);
t_info			*get_info(t_file *file);

/*
** Stock
*/
int				cub_exit(void *param);
t_stock			*init_stock(t_info *info);
double			init_stock_find_dirx(char player_orientation);
double			init_stock_find_diry(char player_orientation);
double			init_stock_find_planx(char player_orientation);
double			init_stock_find_plany(char player_orientation);
void			free_stock(t_stock *stock);
void			raycasting(t_stock *stock);
void			print_t_stock(t_stock *stock);
int				key_pressed(int keycode, void *param);
int				key_released(int keycode, void *param);

/*
** Render
*/
int				render(void *param);
void			lmlx_push_img(t_img *img);
void			player_update(t_stock *s);
void			lmlx_destroy_image(t_img *img);
void			perform_raycasting(t_stock *stock);
void			lmlx_pixel_put(t_img *img, int rgb, int x, int y);
void			draw_vert_line(t_stock *stock, int y_start, int y_end);
char			cub_side_hited(double raydirx, double raydiry, int side);
t_img			*lmlx_new_image(void *mlx_ptr, void *win_ptr, int w, int h);
void			draw_background(t_img *img, int color_ceiling, int color_floor);
void			init_stock_xpm(t_stock *stock);
t_img			*lmlx_xpm_to_img(void *mlx_ptr, char *path);
void			draw_line_text(t_stock *s, int start, int end, int lineheight);

#endif
