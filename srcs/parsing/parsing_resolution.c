/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:58:47 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/21 11:03:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	print_resolution_error(t_err err)
{
	if (err == ERR_RESOLUTION_FORMAT)
		l_printf("[RES ERROR] : %s", ERR_MSG_RES_FORMAT);
	else if (err == ERR_RESOLUTION_VAL_X)
		l_printf("[RES ERROR] : %s", ERR_MSG_RES_VALUE_X);
	else if (err == ERR_RESOLUTION_VAL_Y)
		l_printf("[RES ERROR] : %s", ERR_MSG_RES_VALUE_Y);
	return (FALSE);
}

t_bool			parsing_resolution_format(char *resolution)
{
	resolution += 2;
	if (l_isnum(*resolution) == TRUE || *resolution == '-')
		while (l_isnum(*resolution) == TRUE || *resolution == '-')
			resolution++;
	else
		return (FALSE);
	if (*resolution == ' ')
		resolution++;
	else
		return (FALSE);
	if (l_isnum(*resolution) == TRUE || *resolution == '-')
		while (l_isnum(*resolution) == TRUE || *resolution == '-')
			resolution++;
	else
		return (FALSE);
	if (*resolution == '\0')
		return (TRUE);
	return (FALSE);
}

t_bool			parsing_resolution(char *resolution)
{
	int x;
	int y;

	if (parsing_resolution_format(resolution) == FALSE)
		return (print_resolution_error(ERR_RESOLUTION_FORMAT));
	resolution += 2;
	x = l_atoi(resolution);
	while (l_isnum(*resolution) == TRUE || *resolution == '-')
		resolution++;
	resolution += 1;
	y = l_atoi(resolution);
	if (x <= 0)
		return (print_resolution_error(ERR_RESOLUTION_VAL_X));
	else if (y <= 0)
		return (print_resolution_error(ERR_RESOLUTION_VAL_Y));
	return (TRUE);
}
