/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:47:09 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/17 11:56:49 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strafe(t_stock *s)
{
	char	**map;

	map = s->map;
	if (s->key & KEY_RIGHT)
	{
		if (map[(int)(s->posy)][(int)(s->posx + s->planx * s->movspeed)] != '1')
			s->posx += s->planx * s->movspeed;
		if (map[(int)(s->posy + s->plany * s->movspeed)][(int)(s->posx)] != '1')
			s->posy += s->plany * s->movspeed;
	}
	else if (s->key & KEY_LEFT)
	{
		if (map[(int)(s->posy)][(int)(s->posx - s->planx * s->movspeed)] != '1')
			s->posx -= s->planx * s->movspeed;
		if (map[(int)(s->posy - s->plany * s->movspeed)][(int)(s->posx)] != '1')
			s->posy -= s->plany * s->movspeed;
	}
}

static void	rotation(t_stock *s)
{
	double olddirx;
	double oldplanx;

	olddirx = s->dirx;
	oldplanx = s->planx;
	if (s->key & KEY_ROTL)
	{
		s->dirx = s->dirx * cos(-s->rotspeed) - s->diry * sin(-s->rotspeed);
		s->diry = olddirx * sin(-s->rotspeed) + s->diry * cos(-s->rotspeed);
		s->planx = s->planx * cos(-s->rotspeed) - s->plany * sin(-s->rotspeed);
		s->plany = oldplanx * sin(-s->rotspeed) + s->plany * cos(-s->rotspeed);
	}
	else if (s->key & KEY_ROTR)
	{
		s->dirx = s->dirx * cos(s->rotspeed) - s->diry * sin(s->rotspeed);
		s->diry = olddirx * sin(s->rotspeed) + s->diry * cos(s->rotspeed);
		s->planx = s->planx * cos(s->rotspeed) - s->plany * sin(s->rotspeed);
		s->plany = oldplanx * sin(s->rotspeed) + s->plany * cos(s->rotspeed);
	}
}

void		player_update(t_stock *s)
{
	char **map;

	map = s->map;
	if (s->key == -1)
		s->key = 0;
	if (s->key & KEY_UP)
	{
		if (map[(int)(s->posy)][(int)(s->posx + s->dirx * s->movspeed)] != '1')
			s->posx += s->dirx * s->movspeed;
		if (map[(int)(s->posy + s->diry * s->movspeed)][(int)(s->posx)] != '1')
			s->posy += s->diry * s->movspeed;
	}
	else if (s->key & KEY_DOWN)
	{
		if (map[(int)(s->posy)][(int)(s->posx - s->dirx * s->movspeed)] != '1')
			s->posx -= s->dirx * s->movspeed;
		if (map[(int)(s->posy - s->diry * s->movspeed)][(int)(s->posx)] != '1')
			s->posy -= s->diry * s->movspeed;
	}
	rotation(s);
	strafe(s);
}
