/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stock_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:46:50 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 15:56:46 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	n_sprites(char **map, char *sprites_id)
{
	int		count;
	char	*x_index;
	char	**y_index;

	count = 0;
	y_index = map;
	while (*y_index)
	{
		x_index = *y_index;
		while (*x_index)
		{
			if (l_c_finder(*x_index, sprites_id) == TRUE)
				count += 1;
			x_index++;
		}
		y_index++;
	}
	return (count);
}

int			init_stock_sprites(t_stock *s)
{
	t_coord *s_index;
	char	*x_index;
	char	**y_index;

	y_index = s->map;
	s->n_sprites = n_sprites(s->map, "2");
	if (!(s->sprites_coords = (t_coord*)malloc(sizeof(t_coord) * s->n_sprites)))
		return (1);
	s_index = s->sprites_coords;
	while (*y_index)
	{
		x_index = *y_index;
		while (*x_index)
		{
			if (l_c_finder(*x_index, "2") == TRUE)
			{
				s_index->x = (double)((x_index - *y_index) + 0.5);
				s_index->y = (double)((y_index - s->map) + 0.5);
				s_index++;
			}
			x_index++;
		}
		y_index++;
	}
	return (0);
}
