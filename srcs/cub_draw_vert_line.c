/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_vert_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:23:06 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/12 11:33:12 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	color_picker(char side_hited)
{
	if (side_hited == 'N')
		return (COLOR_NORTH);
	else if (side_hited == 'S')
		return (COLOR_SOUTH);
	else if (side_hited == 'E')
		return (COLOR_EAST);
	else if (side_hited == 'W')
		return (COLOR_WEST);
	return (0);
}

/*
** Will draw a vertical line.
*/
void		draw_vert_line(t_stock *stock, int y_start, int y_end)
{
	int color;

	color = color_picker(stock->side_hited);
	while (y_start < y_end)
	{
		lmlx_pixel_put(stock->img, color, stock->x, y_start);
		y_start++;
	}
}
