/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:07:59 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/14 16:38:52 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_background(t_img *img, int color_ceiling, int color_floor)
{
	int	*temp;
	int	*max_floor;
	int	*max_ceiling;

	temp = img->data_ptr;
	max_floor = (img->width * img->height) + temp;
	max_ceiling = ((img->width * img->height) / 2) + temp;
	while (temp < max_ceiling)
	{
		*temp = color_ceiling;
		temp++;
	}
	while (temp < max_floor)
	{
		*temp = color_floor;
		temp++;
	}
}
