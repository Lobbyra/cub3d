/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_side_hited.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:02:44 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/17 12:03:03 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	side_hited_between(double raydiry, int side)
{
	if (raydiry < 0)
	{
		if (side == VERTICAL)
			return ('E');
		else
			return ('S');
	}
	else
	{
		if (side == VERTICAL)
			return ('E');
		else
			return ('N');
	}
	return ('Z');
}

char		cub_side_hited(double raydirx, double raydiry, int side)
{
	if (raydirx > 0)
	{
		if (raydiry < 0)
		{
			if (side == VERTICAL)
				return ('W');
			else
				return ('S');
		}
		else
		{
			if (side == VERTICAL)
				return ('W');
			else
				return ('N');
		}
	}
	return (side_hited_between(raydiry, side));
}
