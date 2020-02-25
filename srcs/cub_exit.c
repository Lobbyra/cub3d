/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:28:03 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/25 16:43:11 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub_exit(void *param)
{
	t_stock *stock;

	stock = (t_stock*)param;
	free_stock(stock);
	exit(0);
	return (0);
}
