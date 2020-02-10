/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:11:50 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/08 15:17:51 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	gm_is_map(char *line)
{
	char *temp;

	temp = l_strclean(l_strdup(line), " ");
	if (l_strbool(temp, &is_map) == TRUE && l_strcmp(line, "") != 0)
	{
		free(temp);
		return (TRUE);
	}
	free(temp);
	return (FALSE);
}

int				get_map(t_file *file)
{
	char *readed;

	readed = NULL;
	if (!(file->raw_map = l_strclean(file->raw_map, " ")))
		return (print_err_file(file->curr_line, ERR_MEMALLOC));
	if (!(file->raw_map = l_strjoindel(file->raw_map, "\n", 1)))
		return (print_err_file(file->curr_line, ERR_MEMALLOC));
	while (get_next_line(file->fd, &readed) > 0
	&& gm_is_map(readed) == TRUE)
	{
		file->curr_line++;
		file->raw_map = l_strjoindel(file->raw_map, l_strclean(readed, " "), 3);
		if (!(file->raw_map))
			return (print_err_file(file->curr_line, ERR_MEMALLOC));
		if (!(file->raw_map = l_strjoindel(file->raw_map, "\n", 1)))
			return (print_err_file(file->curr_line, ERR_MEMALLOC));
	}
	if (!(file->raw_map = l_strcut(file->raw_map, -1)))
		return (print_err_file(file->curr_line, ERR_MEMALLOC));
	free(readed);
	close(file->fd);
	return (SUCCESS);
}
