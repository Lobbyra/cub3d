/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:40:58 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/21 11:57:05 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** The code below is a protection when the wall is too much high.
**  if (lineheight > WALL_HEIGHT_PROTECTION)
**		lineheight = WALL_HEIGHT_PROTECTION;
*/

static void	draw_wall(t_stock *stock)
{
	int drawend;
	int drawstart;
	int lineheight;

	lineheight = (int)(stock->h / stock->perpwalldist);
	if (lineheight > WALL_HEIGHT_PROTECTION)
		lineheight = WALL_HEIGHT_PROTECTION;
	drawstart = -lineheight / 2 + stock->h / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + stock->h / 2;
	if (drawend >= stock->h)
		drawend = stock->h - 1;
	if (stock->key & KEY_DEBUG)
		draw_vert_line(stock, drawstart, drawend);
	else
		draw_line_text(stock, drawstart, drawend, lineheight);
}

static void	throwing(t_stock *s)
{
	t_bool	is_hit;

	is_hit = FALSE;
	while (is_hit == FALSE)
	{
		if (s->sidedistx < s->sidedisty)
		{
			s->sidedistx += s->deltadistx;
			s->mapx += s->stepx;
			s->side = 0;
		}
		else
		{
			s->sidedisty += s->deltadisty;
			s->mapy += s->stepy;
			s->side = 1;
		}
		if (s->map[s->mapy][s->mapx] == '1')
			is_hit = TRUE;
	}
	if (s->side == 0)
		s->perpwalldist = (s->mapx - s->posx + (1 - s->stepx) / 2) / s->raydirx;
	else
		s->perpwalldist = (s->mapy - s->posy + (1 - s->stepy) / 2) / s->raydiry;
	s->side_hited = cub_side_hited(s->raydirx, s->raydiry, s->side);
}

static void	setup_ray(t_stock *s)
{
	s->camerax = 2 * s->x / (double)(s->w) - 1;
	s->raydirx = s->dirx + s->planx * s->camerax;
	s->raydiry = s->diry + s->plany * s->camerax;
	s->deltadistx = fabs(1 / s->raydirx);
	s->deltadisty = fabs(1 / s->raydiry);
	if (s->raydirx < 0)
	{
		s->stepx = -1;
		s->sidedistx = (s->posx - s->mapx) * s->deltadistx;
	}
	else
	{
		s->stepx = 1;
		s->sidedistx = (s->mapx + 1.0 - s->posx) * s->deltadistx;
	}
	if (s->raydiry < 0)
	{
		s->stepy = -1;
		s->sidedisty = (s->posy - s->mapy) * s->deltadisty;
	}
	else
	{
		s->stepy = 1;
		s->sidedisty = (s->mapy + 1.0 - s->posy) * s->deltadisty;
	}
}

void		perform_raycasting(t_stock *stock)
{
	while (stock->x < stock->w)
	{
		setup_ray(stock);
		throwing(stock);
		draw_wall(stock);
		stock->x++;
		stock->mapx = (int)stock->posx;
		stock->mapy = (int)stock->posy;
	}
	stock->x = 0;
}
