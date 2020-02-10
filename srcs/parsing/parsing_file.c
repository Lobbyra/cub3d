/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:32:29 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/21 11:01:30 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** If there is an error, print it and return FAILURE.
*/

t_bool	parsing_file(t_file *file)
{
	if (parsing_resolution(file->raw_res) == FAILURE)
		return (FAILURE);
	if (parsing_path(file->raw_n_path) == FAILURE)
		return (FAILURE);
	if (parsing_path(file->raw_s_path) == FAILURE)
		return (FAILURE);
	if (parsing_path(file->raw_e_path) == FAILURE)
		return (FAILURE);
	if (parsing_path(file->raw_w_path) == FAILURE)
		return (FAILURE);
	if (parsing_path(file->raw_sprite_path) == FAILURE)
		return (FAILURE);
	if (parsing_color(file->raw_floor_color) == FAILURE)
		return (FAILURE);
	if (parsing_color(file->raw_ceiling_color) == FAILURE)
		return (FAILURE);
	if (parsing_map(file->raw_map, file->curr_line) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
