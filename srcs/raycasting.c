/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:04:21 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/11 11:32:19 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_stock *stock)
{
	mlx_hook(stock->win_ptr, 2, 0, &key_pressed, stock);
	mlx_hook(stock->win_ptr, 3, 0, &key_released, stock);
	mlx_hook(stock->win_ptr, 17, 0, &cub_exit, stock);
	mlx_loop_hook(stock->mlx_ptr, &render, stock);
	mlx_loop(stock->mlx_ptr);
}
