/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:11:50 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/15 14:26:16 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_map(t_file *file)
{
	char *readed;

	readed = NULL;
	while (get_next_line(file->fd, &readed) > 0
	&& l_strbool(l_strclean(readed, " "), &is_map) == TRUE
	&& l_strcmp(readed, "") != 0)
	{
		file->curr_line++;
		if (!(file->raw_map = l_strjoin(file->raw_map, "\n")))
			return (print_err_file(file->curr_line, ERR_MEMALLOC));
		if(!(file->raw_map = l_strjoin(l_strclean(file->raw_map, " "), readed)))
			return (print_err_file(file->curr_line, ERR_MEMALLOC));
	}
	if (!(file->raw_map = l_strcut(file->raw_map, -1)))
		return (print_err_file(file->curr_line, ERR_MEMALLOC));
	return (SUCCESS);
}
