/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:28:03 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/10 15:38:22 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub_exit(void *param)
{
	t_stock *stock;

	stock = (t_stock*)param;
	free_stock(stock);
	mlx_destroy_window(stock->mlx_ptr, stock->win_ptr);
	exit(0);
	return (0);
}
