/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:59:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 10:16:50 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file(t_file *file)
{
	if (file)
	{
		if (raw_res)
			free(raw_res);
		if (raw_n_path)
			free(raw_n_path);
		if (raw_s_path)
			free(raw_s_path);
		if (raw_e_path)
			free(raw_e_path);
		if (raw_w_path)
			free(raw_w_path);
		if (raw_sprite_path)
			free(raw_sprite_path);
		if (raw_map)
			l_freestrs(raw_map);
		free(file);
	}
}
