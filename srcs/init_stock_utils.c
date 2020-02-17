/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stock_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:42:41 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/17 12:53:28 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
