/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:39:05 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/10 15:05:10 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_t_info(t_info *info)
{
	int *floor_color_rgb;
	int *ceiling_color_rgb;

	ft_printf("[res_x = %d]\n", info->res_x);
	ft_printf("[res_y = %d]\n", info->res_y);
	ft_printf("[n_path = %s]\n", info->n_path);
	ft_printf("[s_path = %s]\n", info->s_path);
	ft_printf("[e_path = %s]\n", info->e_path);
	ft_printf("[w_path = %s]\n", info->w_path);
	ft_printf("[sprite_path = %s]\n", info->sprite_path);
	floor_color_rgb = l_get_rgb(info->floor_color);
	ft_printf("[floor_color = %d, ", info->floor_color);
	ft_printf("r = %d, ", floor_color_rgb[0]);
	ft_printf("g = %d, ", floor_color_rgb[1]);
	ft_printf("b = %d]\n", floor_color_rgb[2]);
	ceiling_color_rgb = l_get_rgb(info->ceiling_color);
	ft_printf("[ceiling_color = %d, ", info->ceiling_color);
	ft_printf("r = %d, ", ceiling_color_rgb[0]);
	ft_printf("g = %d, ", ceiling_color_rgb[1]);
	ft_printf("b = %d]\n", ceiling_color_rgb[2]);
	ft_printf("[map = \n{\n");
	l_putstrs_fd(info->map, "\n", STDOUT_FD);
	ft_printf("{\n");
	ft_printf("[player_orientation = %c]\n", info->player_orientation);
}
