/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:09:31 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/10 14:59:05 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_info(t_info *info)
{
	if (info)
	{
		if (info->n_path)
			free(info->n_path);
		if (info->s_path)
			free(info->s_path);
		if (info->e_path)
			free(info->e_path);
		if (info->w_path)
			free(info->w_path);
		if (info->sprite_path)
			free(info->sprite_path);
		if (info->map)
			l_freestrs(info->map);
		free(info);
	}
}
