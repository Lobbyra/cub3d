/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:13:29 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/17 15:59:20 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define malloc

/*
** Beware to put a duplication of the map.
** Return TRUE if the map is ok.
** Print error and return FALSE if tha map is not correct.
*/

/*CHECK*/
t_bool	map_print_err(t_err err, int curr_line, char **arr)
{
	l_freestrs(arr);
	l_putstr("Error\n");
	if (err == ERR_MAP_HOLE)
		ft_printf("[MAP ERROR] Line %d : %s", curr_line, ERR_MSG_MAP_HOLE);
	else if (err == ERR_MAP_PLAY404)
		ft_printf("[MAP ERROR] %s", ERR_MSG_MAP_PLAY404);
	else if (err == ERR_MAP_PLAYDUP)
		ft_printf("[MAP ERROR] Line %d : %s", curr_line, ERR_MSG_MAP_PLAYDUP);
	else if (err == ERR_MSG_MALLOC)
		ft_printf("[MAP ERROR] %s", ERR_MSG_MALLOC);
	return (FALSE);
}

/*CHECK*/
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

/* Return TRUE if line is surrounded by 1*/
/*CHECK*/
t_bool	border_isok(char *line)
{
	if (line[0] == '1' && line[l_strlen(line) - 1] == '1')
		return (TRUE);
	return (FALSE);
}


/* Return index of last empty case*/
/*CHECK*/
int		last_empty(char *line)
{
	int i;

	i = l_strlen(line) - 1;
	while (line[i] != '0' && line[i] != '2' && i > 0)
		i--;
	return (i);
}

/*CHECK*/
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

t_err	checkline(char *prev, char *curr, t_bool *player_saw)
{
	if (border_isok(curr) == FALSE)
		return (ERR_MAP_HOLE);
	if (curr_line_len_isok(prev, curr) == FALSE)
		return (ERR_MAP_HOLE);
	if (how_many_players(curr) > 1
		|| (how_many_players(curr) == 1 && *player_saw == TRUE))
		return (ERR_MAP_PLAYDUP);
	if (how_many_players(curr) == 1 && *player_saw == FALSE)
		*player_saw = TRUE;
	return (SUCCESS);
}

t_bool	parsing_map(char *map, int curr_line)
{
	int		i;
	t_err	err;
	int		len_arr;
	char	**arr;
	t_bool	player_saw;

	i = 1;
	player_saw = FALSE;
	if (!(arr = l_split(map, "\n"))
		return (map_print_err(ERR_MAP_MEMALLOC, curr_line, arr));
	if (l_stris_c(arr[0], '1') == FALSE)
		return (map_print_err(ERR_MAP_HOLE, curr_line, arr));
	len_arr = l_strarr_len(arr);
	while (i < len_arr)
	{
		err = checkline(arr[i - 1], arr[i], &player_saw);
		if (err != SUCCESS)
			return (map_print_err(err, curr_line + i, arr));
		i++;
	}
	if (player_saw == FALSE)
		return (map_print_err(ERR_MAP_PLAY404, curr_line, arr));
	l_freestrs(arr);
	return (SUCCESS);
}
