/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:06:42 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/12 11:44:15 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_pressed(int keycode, void *param)
{
	t_stock *stock;

	stock = (t_stock*)param;
	if (keycode == KEY_Z)
		stock->key |= KEY_UP;
	else if (keycode == KEY_S)
		stock->key |= KEY_DOWN;
	else if (keycode == KEY_Q)
		stock->key |= KEY_LEFT;
	else if (keycode == KEY_D)
		stock->key |= KEY_RIGHT;
	else if (keycode == KEY_ARRL)
		stock->key |= KEY_ROTL;
	else if (keycode == KEY_ARRR)
		stock->key |= KEY_ROTR;
	else if (keycode == KEY_ALT)
		stock->key ^= KEY_DEBUG;
	else if (keycode == KEY_ESCAPE)
		cub_exit(stock);
	return (1);
}

int		key_released(int keycode, void *param)
{
	t_stock *stock;

	stock = (t_stock*)param;
	if (keycode == KEY_Z)
		stock->key &= ~KEY_UP;
	else if (keycode == KEY_S)
		stock->key &= ~KEY_DOWN;
	else if (keycode == KEY_Q)
		stock->key &= ~KEY_LEFT;
	else if (keycode == KEY_D)
		stock->key &= ~KEY_RIGHT;
	else if (keycode == KEY_ARRL)
		stock->key &= ~KEY_ROTL;
	else if (keycode == KEY_ARRR)
		stock->key &= ~KEY_ROTR;
	return (1);
}
