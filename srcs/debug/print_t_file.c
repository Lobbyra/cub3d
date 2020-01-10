/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:48:32 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 15:54:23 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_t_file(t_file *file)
{
	ft_printf("[fd = %d]\n", file->fd);
	ft_printf("[raw_res = %s]\n", file->raw_res);
	ft_printf("[raw_n_path = %s]\n", file->raw_n_path);
	ft_printf("[raw_s_path = %s]\n", file->raw_s_path);
	ft_printf("[raw_e_path = %s]\n", file->raw_e_path);
	ft_printf("[raw_w_path = %s]\n", file->raw_w_path);
	ft_printf("[raw_sprite_path = %s]\n", file->raw_sprite_path);
	ft_printf("[raw_map = %s]\n", file->raw_map);
	ft_printf("[curr_line = %d]\n", file->curr_line);
	ft_printf("[player_orientation = %c]\n", file->player_orientation);
}
