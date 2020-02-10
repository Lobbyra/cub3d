/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:53:05 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/22 14:42:18 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_file	*init_file(void)
{
	t_file	*new;

	if (!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	new->raw_res = NULL;
	new->raw_n_path = NULL;
	new->raw_s_path = NULL;
	new->raw_e_path = NULL;
	new->raw_w_path = NULL;
	new->raw_sprite_path = NULL;
	new->raw_floor_color = NULL;
	new->raw_ceiling_color = NULL;
	new->raw_map = NULL;
	new->curr_line = 0;
	errno = 0;
	return (new);
}
