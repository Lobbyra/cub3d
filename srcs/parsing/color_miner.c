/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_miner_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:20:44 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/24 09:39:44 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Format of rgbs : 251,68,54 as r,g,b
*/

int	color_miner(char *rgb)
{
	int		color;
	char	**colors;

	colors = l_split(rgb, ",");
	color = l_atoi(colors[0]);
	color = (color << 8) + l_atoi(colors[1]);
	color = (color << 8) + l_atoi(colors[2]);
	l_freestrs(colors);
	return (color);
}
