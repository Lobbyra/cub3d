/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:23:31 by Lobbyra           #+#    #+#             */
/*   Updated: 2019/12/19 17:42:11 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char *get_path(char *line, int flag)
{

}

static int	line_detector(char *line)
{
	if (l_strncmp(line, "NO", 2) == 0)
		return (FLAG_PATH_NORTH);
	else if (l_strncmp(line, "SO", 2) == 0)
		return (FLAG_PATH_SOUTH);
	else if (l_strncmp(line, "EA", 2) == 0)
		return (FLAG_PATH_EAST);
	else if (l_strncmp(line, "WE", 2) == 0)
		return (FLAG_PATH_WEST);
	else if (l_strncmp(line, "R", 1) == 0)
		return (FLAG_RESOLUTION);
	else if (l_strncmp(line, "S", 1) == 0)
		return (FLAG_PATH_SPRITE);
	else if (l_strncmp(line, "F", 1) == 0)
		return (FLAG_COLOR_FLOOR);
	else if (l_strncmp(line, "C", 1) == 0)
		return (FLAG_COLOR_CEILING);
	else if (l_strcmp(line, "") == 0)
		return (FLAG_EMPTY);
	else
		return (FLAG_UNKNOW);
}

t_err		parsing_header(t_file *file)
{

}
