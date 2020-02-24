/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 09:17:36 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 15:35:48 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		get_player(char **map)
{
	char *temp;

	while (map != NULL)
	{
		temp = *map;
		while (l_c_finder(*temp, "NSEW") == FALSE && *temp != '\0')
			temp++;
		if (l_c_finder(*temp, "NSEW") == TRUE)
			break ;
		map++;
	}
	return (*temp);
}

t_info			*get_info(t_file *file)
{
	int		*res;
	t_info	*info;

	res = resolution_miner(file->raw_res);
	if (!(info = init_info()))
		return (NULL);
	info->res_x = res[0];
	info->res_y = res[1];
	free(res);
	if (!(info->n_path = path_miner(file->raw_n_path)))
		return (NULL);
	if (!(info->s_path = path_miner(file->raw_s_path)))
		return (NULL);
	if (!(info->e_path = path_miner(file->raw_e_path)))
		return (NULL);
	if (!(info->w_path = path_miner(file->raw_w_path)))
		return (NULL);
	if (!(info->sprite_path = path_miner(file->raw_sprite_path)))
		return (NULL);
	info->floor_color = color_miner(file->raw_floor_color + 2);
	info->ceiling_color = color_miner(file->raw_ceiling_color + 2);
	if (!(info->map = l_split(file->raw_map, "\n")))
		return (NULL);
	info->player_orientation = get_player(info->map);
	return (info);
}
