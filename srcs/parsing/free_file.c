/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:59:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/15 11:19:21 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file(t_file *file)
{
	if (file)
	{
		if (file->raw_res)
			free(file->raw_res);
		if (file->raw_n_path)
			free(file->raw_n_path);
		if (file->raw_s_path)
			free(file->raw_s_path);
		if (file->raw_e_path)
			free(file->raw_e_path);
		if (file->raw_w_path)
			free(file->raw_w_path);
		if (file->raw_sprite_path)
			free(file->raw_sprite_path);
		if (file->raw_floor_color)
			free(file->raw_floor_color);
		if (file->raw_ceiling_color)
			free(file->raw_ceiling_color);
		if (file->raw_map)
			free(file->raw_map);
		free(file);
	}
}
