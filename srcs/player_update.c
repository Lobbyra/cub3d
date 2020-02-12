/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:47:09 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/12 17:00:13 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strafe(t_stock *s)
{
	char	**map;

	map = s->map;
	if (s->key & KEY_RIGHT)
	{
		if (s->map[(int)(s->posy)][(int)(s->posx - s->dirx * s->movspeed)] != '1')
			s->posx -= s->dirx * s->movspeed;
		if (s->map[(int)(s->posy - s->diry * s->movspeed)][(int)(s->posx)] != '1')
			s->posy -= s->diry * s->movspeed;

	}
	else if (s->key & KEY_LEFT)
	{
		if (s->map[(int)(s->posy)][(int)(s->posx - s->dirx * s->movspeed)] != '1')
			s->posx -= s->dirx * s->movspeed;
		if (s->map[(int)(s->posy - s->diry * s->movspeed)][(int)(s->posx)] != '1')
			s->posy -= s->diry * s->movspeed;
	}
}

static void	rotation(t_stock *s)
{
	double olddirX;
	double oldPlaneX;

	olddirX = s->dirx;
	oldPlaneX = s->planex;
	if (s->key & KEY_ROTL)
	{
		s->dirx = s->dirx * cos(-s->rotspeed) - s->diry * sin(-s->rotspeed);
		s->diry = olddirX * sin(-s->rotspeed) + s->diry * cos(-s->rotspeed);
		s->planex = s->planex * cos(-s->rotspeed) - s->planey * sin(-s->rotspeed);
		s->planey = oldPlaneX * sin(-s->rotspeed) + s->planey * cos(-s->rotspeed);
	}
	else if (s->key & KEY_ROTR)
	{
		s->dirx = s->dirx * cos(s->rotspeed) - s->diry * sin(s->rotspeed);
		s->diry = olddirX * sin(s->rotspeed) + s->diry * cos(s->rotspeed);
		s->planex = s->planex * cos(s->rotspeed) - s->planey * sin(s->rotspeed);
		s->planey = oldPlaneX * sin(s->rotspeed) + s->planey * cos(s->rotspeed);
	}
}

void	player_update(t_stock *s)
{
	char **map;

	map = s->map;
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
