/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:59:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 16:08:35 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	*parsing(char *path)
{
	t_file	*file;
	t_info	*info;

	file = init_file();
	get_file(file, path);
	if (parsing_infos(file) == FAILURE)
		return (NULL);
	if (parsing_map(file) == FAILURE)
		return (NULL);
	info = get_info(file);
	return (info);
}
