/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:39:05 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/08 15:18:21 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pi_part2(t_info *info)
{
	int *floor_color_rgb;
	int *ceiling_color_rgb;

	l_printf("[res_x = %d]\n", info->res_x);
	l_printf("[res_y = %d]\n", info->res_y);
	l_printf("[n_path = %s]\n", info->n_path);
	l_printf("[s_path = %s]\n", info->s_path);
	l_printf("[e_path = %s]\n", info->e_path);
	l_printf("[w_path = %s]\n", info->w_path);
	l_printf("[sprite_path = %s]\n", info->sprite_path);
	floor_color_rgb = l_get_rgb(info->floor_color);
	l_printf("[floor_color = %d, ", info->floor_color);
	l_printf("r = %d, ", floor_color_rgb[0]);
	l_printf("g = %d, ", floor_color_rgb[1]);
	l_printf("b = %d]\n", floor_color_rgb[2]);
	ceiling_color_rgb = l_get_rgb(info->ceiling_color);
	l_printf("[ceiling_color = %d, ", info->ceiling_color);
	l_free(2, floor_color_rgb, ceiling_color_rgb);
	l_printf("r = %d, ", ceiling_color_rgb[0]);
	l_printf("g = %d, ", ceiling_color_rgb[1]);
	l_printf("b = %d]\n", ceiling_color_rgb[2]);
	l_printf("[map = \n{\n");
	l_putstrs_fd(info->map, "\n", STDOUT_FD);
	l_printf("{\n");
	l_printf("[player_orientation = %c]\n", info->player_orientation);
}

void		print_t_info(t_info *info)
{
	pi_part2(info);
}
