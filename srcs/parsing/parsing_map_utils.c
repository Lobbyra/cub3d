/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:13:29 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/08 15:13:46 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	map_print_err(t_err err, int curr_line, char **arr)
{
	l_freestrs(arr);
	l_putstr("Error\n");
	if (err == ERR_MAP_HOLE)
		l_printf("[MAP ERROR] Line %d : %s", curr_line, ERR_MSG_MAP_HOLE);
	else if (err == ERR_MAP_PLAY404)
		l_printf("[MAP ERROR] %s", ERR_MSG_MAP_PLAY404);
	else if (err == ERR_MAP_PLAYDUP)
		l_printf("[MAP ERROR] Line %d : %s", curr_line, ERR_MSG_MAP_PLAYDUP);
	else if (err == ERR_MAP_MEMALLOC)
		l_printf("[MAP ERROR] %s", ERR_MSG_MALLOC);
	return (FALSE);
}

int		how_many_players(char *line)
{
	int count;

	count = 0;
	while (*line)
	{
		if (l_c_finder(*line, "NSEW") == TRUE)
			count++;
		line++;
	}
	return (count);
}

t_bool	border_isok(char *line)
{
	if (line[0] == '1' && line[l_strlen(line) - 1] == '1')
		return (TRUE);
	return (FALSE);
}

int		last_empty(char *line)
{
	int i;

	i = l_strlen(line) - 1;
	while (line[i] != '0' && line[i] != '2' && i > 0)
		i--;
	return (i);
}

t_bool	curr_line_len_isok(char *prev, char *curr)
{
	if (!prev || !curr)
		return (FALSE);
	if ((int)l_strlen(curr) - 1 < last_empty(prev))
		return (FALSE);
	else if ((int)l_strlen(prev) - 1 < last_empty(curr))
		return (FALSE);
	return (TRUE);
}
