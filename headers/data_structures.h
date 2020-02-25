/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:58:31 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/25 16:33:53 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURES_H
# define DATA_STRUCTURES_H

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_bmp
{
	char		magic[3];
	int			size_file;
	int			app_spe;
	int			data_offset;
	int			size_dib;
	int			w;
	int			h;
	short int	planes;
	short int	bpp;
	int			*data_ptr;
	double		padding_trash;
}				t_bmp;

typedef struct	s_sprite
{
	double		transformy;
	int			spritescreenx;
	int			spritew;
	int			spriteh;
	int			drawstartx;
	int			drawendx;
	int			drawstarty;
	int			drawendy;
}				t_sprite;

typedef struct	s_file
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

typedef struct	s_info
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
	int			*data_ptr;
}				t_img;

typedef struct	s_stock
{
	int			w;
	int			h;
	t_img		*img;
	t_img		*text_n;
	t_img		*text_s;
	t_img		*text_e;
	t_img		*text_w;
	t_img		*text_sp;
	char		**map;
	char		*n_path;
	char		*s_path;
	char		*e_path;
	char		*w_path;
	void		*mlx_ptr;
	void		*win_ptr;
	double		mspeed;
	int			floor_color;
	char		*sprite_path;
	int			n_sprites;
	t_coord		*sprites_coords;
	double		*zbuffer;
	int			ceiling_color;
	double		rspeed;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
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

#endif
