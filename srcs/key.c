/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:06:42 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/10 15:42:21 by jecaudal         ###   ########.fr       */
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
	else if (keycode == KEY_ESCAPE)
		cub_exit(stock);
	l_printf("stock->key = %d\n", stock->key);
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
	l_printf("stock->key = %d\n", stock->key);
	return (1);
}
