/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:59:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 13:13:33 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	*panic_file(t_file *file)
{
	free_file(file);
	return (NULL);
}

t_info	*parsing(char *path)
{
	t_file	*file;
	t_info	*info;

	file = init_file();
	if (get_file(file, path) == FAILURE)
		return (panic_file(file));
	if (parsing_file(file) == FALSE)
		return (panic_file(file));
	info = get_info(file);
	free_file(file);
	return (info);
}
