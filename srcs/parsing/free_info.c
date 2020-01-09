/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:09:31 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 10:14:29 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_info(t_info *info)
{
	if (info)
	{
		if (n_path)
			free(n_path);
		if (s_path)
			free(s_path);
		if (e_path)
			free(e_path);
		if (w_path)
			free(w_path);
		if (sprite_path)
			free(sprite_path);
		if (map)
			free(map);
		free(info);
	}
}
