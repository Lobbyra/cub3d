/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:47:09 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 10:38:22 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strafe(t_stock *s)
{
	double	temp;

	if (s->key & KEY_RIGHT)
	{
		temp = s->posx + (s->planx * s->mspeed);
		if (l_c_finder(s->map[(int)(s->posy)][(int)(temp)], "12") == FALSE)
			s->posx += s->planx * s->mspeed;
		temp = s->posy + (s->plany * s->mspeed);
		if (l_c_finder(s->map[(int)(temp)][(int)(s->posx)], "12") == FALSE)
			s->posy += s->plany * s->mspeed;
	}
	else if (s->key & KEY_LEFT)
	{
		temp = s->posx - (s->planx * s->mspeed);
		if (l_c_finder(s->map[(int)(s->posy)][(int)(temp)], "12") == FALSE)
			s->posx -= s->planx * s->mspeed;
		temp = s->posy - (s->plany * s->mspeed);
		if (l_c_finder(s->map[(int)(temp)][(int)(s->posx)], "12") == FALSE)
			s->posy -= s->plany * s->mspeed;
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
		s->dirx = s->dirx * cos(-s->rspeed) - s->diry * sin(-s->rspeed);
		s->diry = olddirx * sin(-s->rspeed) + s->diry * cos(-s->rspeed);
		s->planx = s->planx * cos(-s->rspeed) - s->plany * sin(-s->rspeed);
		s->plany = oldplanx * sin(-s->rspeed) + s->plany * cos(-s->rspeed);
	}
	else if (s->key & KEY_ROTR)
	{
		s->dirx = s->dirx * cos(s->rspeed) - s->diry * sin(s->rspeed);
		s->diry = olddirx * sin(s->rspeed) + s->diry * cos(s->rspeed);
		s->planx = s->planx * cos(s->rspeed) - s->plany * sin(s->rspeed);
		s->plany = oldplanx * sin(s->rspeed) + s->plany * cos(s->rspeed);
	}
}

void		player_update(t_stock *s)
{
	double temp;

	if (s->key == -1)
		s->key = 0;
	if (s->key & KEY_UP)
	{
		temp = s->posx + (s->dirx * s->mspeed);
		if (l_c_finder(s->map[(int)(s->posy)][(int)(temp)], "12") == FALSE)
			s->posx += s->dirx * s->mspeed;
		temp = s->posy + (s->diry * s->mspeed);
		if (l_c_finder(s->map[(int)(temp)][(int)(s->posx)], "12") == FALSE)
			s->posy += s->diry * s->mspeed;
	}
	if (s->key & KEY_DOWN)
	{
		temp = s->posx - (s->dirx * s->mspeed);
		if (l_c_finder(s->map[(int)(s->posy)][(int)(temp)], "12") == FALSE)
			s->posx = temp;
		temp = s->posy - (s->diry * s->mspeed);
		if (l_c_finder(s->map[(int)(temp)][(int)(s->posx)], "12") == FALSE)
			s->posy = temp;
	}
	rotation(s);
	strafe(s);
}
