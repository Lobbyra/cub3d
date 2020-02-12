/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:00:08 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/11 15:32:27 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	isk_find_y_player(char **map)
{
	char	*temp;
	char	**save_map;

	save_map = map;
	while (map != NULL)
	{
		temp = *map;
		while (l_c_finder(*temp, "NSEW") == FALSE && *temp != '\0')
			temp++;
		if (l_c_finder(*temp, "NSEW") == TRUE)
			break ;
		map++;
	}
	return (map - save_map);
}

static int	isk_find_x_player(char **map)
{
	char	*temp;

	while (map != NULL)
	{
		temp = *map;
		while (l_c_finder(*temp, "NSEW") == FALSE && *temp != '\0')
			temp++;
		if (l_c_finder(*temp, "NSEW") == TRUE)
			break ;
		map++;
	}
	return (temp - *map);
}

static void	isk_default(t_stock *stock, char player_orientation)
{
	stock->posx = isk_find_x_player(stock->map);
	stock->posy = isk_find_y_player(stock->map);
	stock->dirx = init_stock_find_dirx(player_orientation);
	stock->diry = init_stock_find_diry(player_orientation);
	stock->planex = init_stock_find_planex(player_orientation);
	stock->planey = init_stock_find_planey(player_orientation);
	stock->camerax = 0;
	stock->is_debug = 0;
	stock->key = 0;
	stock->x = 0;
	stock->stepx = 0;
	stock->stepy = 0;
	stock->raydirx = 0;
	stock->raydiry = 0;
	stock->deltadistx = 0;
	stock->deltadisty = 0;
	stock->perpwalldist = 0;
	stock->sidedistx = 0;
	stock->sidedisty = 0;
	stock->mapx = (int)stock->posx;
	stock->mapy = (int)stock->posy;
	stock->fov = CUB_FOV;
	stock->movspeed = CUB_MSPEED;
	stock->rotspeed = CUB_RSPEED;
}

static void	isk_infocpy(t_info *info, t_stock *stock)
{
	stock->w = info->res_x;
	stock->h = info->res_y;
	stock->n_path = l_strdup(info->n_path);
	stock->s_path = l_strdup(info->s_path);
	stock->e_path = l_strdup(info->e_path);
	stock->w_path = l_strdup(info->w_path);
	stock->sprite_path = l_strdup(info->sprite_path);
	stock->floor_color = info->floor_color;
	stock->ceiling_color = info->ceiling_color;
	stock->map = l_strsdup(info->map);
}

t_stock		*init_stock(t_info *info)
{
	t_stock *stock;

	if (!(stock = (t_stock*)malloc(sizeof(t_stock))))
	return (NULL);
	isk_infocpy(info, stock);
	isk_default(stock, info->player_orientation);
	stock->map[(int)stock->posy][(int)stock->posx] = '0';
	if (stock->w > WIDTH_SCREEN || stock->h > HEIGHT_SCREEN)
	{
		stock->w = 2560;
		stock->h = 1440;
	}
	return (stock);
}
