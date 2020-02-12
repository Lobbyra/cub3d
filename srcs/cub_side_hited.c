/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_side_hited.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:02:44 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/12 17:09:24 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	side_hited_between(double raydirx, double raydiry, int side)
{
	if (raydirx > 0 && raydirx < 1 && raydiry > -1 && raydiry < 0) //NE
	{
		if (side == VERTICAL)
			return ('W');
		return ('S');
	}
	else if (raydirx > -1 && raydirx < 0 && raydiry > -1 && raydiry < 0) //NW
	{
		if (side == VERTICAL)
			return ('E');
		return ('S');
	}
	else if (raydirx > 0 && raydirx < 1 && raydiry > 0 && raydiry < 1) //SE
	{
		if (side == VERTICAL)
			return ('W');
		return ('N');
	}
	else if (raydirx > -1 && raydirx < 0 && raydiry > 0 && raydiry < 1) //SW
	{
		if (side == VERTICAL)
			return ('E');
		return ('N');
	}
	return ('N');
}

char		cub_side_hited(double raydirx, double raydiry, int side)
{
	if (raydirx == 1 && raydiry == 0)
		return ('E');
	else if (raydirx == -1 && raydiry == 0)
		return ('W');
	else if (raydirx == 0 && raydiry == 1)
		return ('S');
	else if (raydirx == 0 && raydiry == -1)
		return ('N');
	else
		return (side_hited_between(raydirx, raydiry, side));
	return ('N');
}
