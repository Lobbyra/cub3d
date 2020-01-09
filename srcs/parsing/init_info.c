/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:47:50 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 09:52:49 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	*init_info(void)
{
	t_info	*new;

	if (!(new = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	new->res_x = -1;
	new->res_y = -1;
	new->n_path = NULL;
	new->s_path = NULL;
	new->e_path = NULL;
	new->w_path = NULL;
	new->sprite_path = NULL;
	new->floor_color = -1;
	new->ceiling_color = -1;
	new->map = NULL;
	return (new);
}
