/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stock_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:42:41 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/18 15:00:23 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_stock_xpm(t_stock *stock)
{
	if (!(stock->text_n = lmlx_xpm_to_img(stock->mlx_ptr, stock->n_path)))
		stock->text_n = NULL;
	if (!(stock->text_s = lmlx_xpm_to_img(stock->mlx_ptr, stock->s_path)))
		stock->text_s = NULL;
	if (!(stock->text_e = lmlx_xpm_to_img(stock->mlx_ptr, stock->e_path)))
		stock->text_e = NULL;
	if (!(stock->text_w = lmlx_xpm_to_img(stock->mlx_ptr, stock->w_path)))
		stock->text_w = NULL;
}

double	init_stock_find_dirx(char player_orientation)
{
	if (player_orientation == 'N' || player_orientation == 'S')
		return (0);
	if (player_orientation == 'E')
		return (1);
	if (player_orientation == 'W')
		return (-1);
	return (0);
}

double	init_stock_find_diry(char player_orientation)
{
	if (player_orientation == 'N')
		return (-1);
	if (player_orientation == 'S')
		return (1);
	if (player_orientation == 'E' || player_orientation == 'W')
		return (0);
	return (0);
}

double	init_stock_find_planx(char player_orientation)
{
	if (player_orientation == 'N')
		return (0.66);
	if (player_orientation == 'S')
		return (-0.66);
	if (player_orientation == 'E' || player_orientation == 'W')
		return (0);
	return (0);
}

double	init_stock_find_plany(char player_orientation)
{
	if (player_orientation == 'N' || player_orientation == 'S')
		return (0);
	if (player_orientation == 'E')
		return (0.66);
	if (player_orientation == 'W')
		return (-0.66);
	return (0);
}
