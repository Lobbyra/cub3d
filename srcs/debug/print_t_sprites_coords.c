/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_sprites_coords.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:16:35 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 16:06:18 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_t_sprites_coords(t_coord *coords, int n_coords)
{
	t_coord *temp;

	temp = coords;
	while (temp - coords < n_coords)
	{
		printf("[%d:x = %f;y = %f]\n", (int)(temp - coords), temp->x, temp->y);
		temp++;
	}
}
