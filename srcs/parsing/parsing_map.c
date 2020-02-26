/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:13:29 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/26 11:30:03 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (!(arr = l_split(map, "\n")))
		return (map_print_err(ERR_MAP_MEMALLOC, curr_line, arr));
	if (l_stris_c(arr[0], '1') == FALSE ||
		l_stris_c(arr[l_strarr_len(arr) - 1], '1') == FALSE)
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
