/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vert_line_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:51:26 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/21 11:22:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*which_texture(t_stock *s)
{
	char c;

	c = s->side_hited;
	if (c == 'N')
		return (s->text_n);
	else if (c == 'S')
		return (s->text_s);
	else if (c == 'E')
		return (s->text_e);
	else if (c == 'W')
		return (s->text_w);
	return (NULL);
}

static int	get_color(t_stock *s, float start, int lineheight)
{
	int		color;
	double	x_text;
	double	x_wall;
	double	y_text;
	t_img	*texture;

	texture = which_texture(s);
	if (s->side == 0)
		x_wall = s->posy + s->perpwalldist * s->raydiry;
	else
		x_wall = s->posx + s->perpwalldist * s->raydirx;
	x_wall -= floor((x_wall));
	x_text = (int)(x_wall * (double)(texture->width));
	if (s->side == 0 && s->raydirx > 0)
		x_text = texture->width - x_text - 1;
	if (s->side == 1 && s->raydiry < 0)
		x_text = texture->width - x_text - 1;
	color = start * 256 - s->h * 128 + lineheight * 128;
    y_text = ((color * texture->height) / lineheight) / 256;
	color = texture->data_ptr[(int)(y_text * texture->width + x_text)];
	return (color);
}

void		draw_line_text(t_stock *s, int start, int end, int lineheight)
{
	int color;

	while (start < end)
	{
		color = get_color(s, start, lineheight);
		s->img->data_ptr[(s->img->width * start) + s->x] = color;
		start++;
	}
}
