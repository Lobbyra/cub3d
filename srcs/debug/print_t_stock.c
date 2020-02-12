/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_stock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:31:33 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/12 11:35:39 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_t_stock(t_stock *stock)
{
	l_printf("[DEBUG]\n[posx = %d]\n", (int)stock->posx);
	l_printf("[posy = %d]\n", (int)stock->posy);
}
