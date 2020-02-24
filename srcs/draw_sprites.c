/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:12:14 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 16:54:30 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	drawing_ext(t_stock *s, t_sprite *sp, int x_stripe, int x_text)
{
	int clr;
	int y_stripe;
	int y_text;

	if (sp->transformy > 0 && x_stripe > 0 && x_stripe < s->w
		&& sp->transformy < s->zbuffer[x_stripe])
	{
		y_stripe = sp->drawstarty;
		while (y_stripe < sp->drawendy)
		{
			clr = y_stripe * 256 - s->h * 128 + sp->spriteh * 128;
			y_text = ((clr * s->text_s->height) / sp->spriteh) / 256;
			clr = s->text_sp->data_ptr[s->text_s->width * y_text + x_text];
			if ((clr & 0x00FFFFFF) != 0)
				s->img->data_ptr[y_stripe * s->img->width + x_stripe] = clr;
			y_stripe++;
		}
	}
}

static void	drawing(t_stock *s, t_sprite *sp)
{
	int		x_text;
	int		x_stripe;

	x_stripe = sp->drawstartx;
	while (x_stripe < sp->drawendx)
	{
		x_text = (int)(256 * (x_stripe - (-sp->spritew / 2 + sp->spritescreenx))
		* s->text_s->width / sp->spritew) / 256;
		if (sp->transformy > 0 && x_stripe > 0 && x_stripe < s->w
			&& sp->transformy < s->zbuffer[x_stripe])
		{
			drawing_ext(s, sp, x_stripe, x_text);
		}
		x_stripe++;
	}
}

static void	drawing_computing(t_stock *s, t_sprite *sp)
{
	sp->drawstarty = -sp->spriteh / 2 + s->h / 2;
	if (sp->drawstarty < 0)
		sp->drawstarty = 0;
	sp->drawendy = sp->spriteh / 2 + s->h / 2;
	if (sp->drawendy >= s->h)
		sp->drawendy = s->h - 1;
	sp->drawstartx = -sp->spritew / 2 + sp->spritescreenx;
	if (sp->drawstartx < 0)
		sp->drawstartx = 0;
	sp->drawendx = sp->spritew / 2 + sp->spritescreenx;
	if (sp->drawendx >= s->w)
		sp->drawendx = s->w - 1;
}

static void	pre_compute(t_stock *s, t_sprite *sp, int i)
{
	double	invdet;
	double	spritex;
	double	spritey;
	double	transformx;

	spritex = s->sprites_coords[i].x - s->posx;
	spritey = s->sprites_coords[i].y - s->posy;
	invdet = 1.0 / (s->planx * s->diry - s->dirx * s->plany);
	transformx = invdet * (s->diry * spritex - s->dirx * spritey);
	sp->transformy = invdet * (-s->plany * spritex + s->planx * spritey);
	sp->spritescreenx = (int)((s->w / 2) * (1 + transformx / sp->transformy));
	sp->spriteh = abs((int)(s->h / (sp->transformy)));
	sp->spritew = abs((int)(s->h / (sp->transformy)));
}

void		draw_sprites(t_stock *s)
{
	int			i;
	t_sprite	sprite_values;

	i = 0;
	sort_sprites(s);
	while (i < s->n_sprites)
	{
		pre_compute(s, &sprite_values, i);
		drawing_computing(s, &sprite_values);
		drawing(s, &sprite_values);
		i++;
	}
}
