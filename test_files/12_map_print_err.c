/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_map_print_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:37:25 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/17 12:54:13 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (FALSE);
}

int		main(int argc, char **argv)
{
	int	arg;

	if (argc < 2)
	return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		map_print_err(ERR_MAP_HOLE, 56, l_split("uifoh udfsioghsudfioghsdufiog hsudfgio hsudfiog hsudio", " "));
	if (arg == 2)
		map_print_err(ERR_MAP_PLAY404, 56, l_split("uifoh udfsioghsudfioghsdufiog hsudfgio hsudfiog hsudio", " "));
	if (arg == 3)
		map_print_err(ERR_MAP_PLAYDUP, 56, l_split("uifoh udfsioghsudfioghsdufiog hsudfgio hsudfiog hsudio", " "));
	return (0);
}
