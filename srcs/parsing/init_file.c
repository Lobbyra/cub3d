/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:53:05 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 09:55:31 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_file	*init_file(void)
{
	t_file	*new;

	if (!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	raw_res = NULL;
	raw_n_path = NULL;
	raw_s_path = NULL;
	raw_e_path = NULL;
	raw_w_path = NULL;
	raw_sprite_path = NULL;
	raw_map = NULL;
	curr_line = 1;

	return (new);
}
