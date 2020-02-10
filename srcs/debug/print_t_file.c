/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:48:32 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 15:33:30 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_t_file(t_file *file)
{
	l_printf("[fd = %d]\n", file->fd);
	l_printf("[raw_res = %s]\n", file->raw_res);
	l_printf("[raw_n_path = %s]\n", file->raw_n_path);
	l_printf("[raw_s_path = %s]\n", file->raw_s_path);
	l_printf("[raw_e_path = %s]\n", file->raw_e_path);
	l_printf("[raw_w_path = %s]\n", file->raw_w_path);
	l_printf("[raw_sprite_path = %s]\n", file->raw_sprite_path);
	l_printf("[raw_floor_color = %s]\n", file->raw_floor_color);
	l_printf("[raw_ceiling_color = %s]\n", file->raw_ceiling_color);
	l_printf("[raw_map = \n%s]\n", file->raw_map);
	l_printf("[curr_line = %d]\n", file->curr_line);
}
