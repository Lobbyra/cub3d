/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:12:14 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 16:06:49 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Coords will sorted by [0] farest.
*/

static void	sort_sprites_bubble(t_stock *s, double *distances)
{
	int		i;
	double	dist_swap;
	t_coord	coord_swap;

	i = 1;
	while (i < s->n_sprites)
	{
		if (distances[i - 1] < distances[i])
		{
			dist_swap = distances[i - 1];
			distances[i - 1] = distances[i];
			distances[i] = dist_swap;
			coord_swap = s->sprites_coords[i - 1];
			s->sprites_coords[i - 1] = s->sprites_coords[i];
			s->sprites_coords[i] = coord_swap;
			i = 1;
		}
		else
			i++;
	}
}

void		sort_sprites(t_stock *s)
{
	int		i;
	double	*distances;

	i = 0;
	if (!(distances = (double*)malloc(sizeof(double) * s->n_sprites)))
		return ;
	while (i < s->n_sprites)
	{
		distances[i] = ((s->posx - s->sprites_coords[i].x) *
		(s->posx - s->sprites_coords[i].x) +
		(s->posy - s->sprites_coords[i].y) *
		(s->posy - s->sprites_coords[i].y));
		i++;
	}
	sort_sprites_bubble(s, distances);
	free(distances);
}
