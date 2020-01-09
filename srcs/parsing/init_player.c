/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:55:43 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 09:58:52 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	*init_player(void)
{
	t_player	*new;

	if (!(new = (t_player*)malloc(sizeof(t_player))))
		return (NULL);
	new->move_speed = MOVE_SPEED;
	new->rotation_speed = ROTATION_SPEED;
	new->fov = FOV;
	return (new);
}
