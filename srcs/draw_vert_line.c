/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vert_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:23:06 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/19 15:44:24 by jecaudal         ###   ########.fr       */
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

void		draw_vert_line(t_stock *s, int y_start, int y_end)
{
	int color;

	color = color_picker(s->side_hited);
	while (y_start < y_end)
	{
		*(s->img->data_ptr + ((s->img->width) * y_start) + s->x) = color;
		y_start++;
	}
}
