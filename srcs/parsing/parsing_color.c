/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:39:55 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/20 10:46:20 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool			print_color_err(t_err err, int curr_line)
{
	if (err == ERR_COLOR_FORMAT)
		ft_printf("[COLOR ERROR] Line %d : %s", curr_line, ERR_MSG_CLR_FORMAT);
	else if (err == ERR_COLOR_VALUE)
		ft_printf("[COLOR ERROR] Line %d : %s", curr_line, ERR_MSG_CLR_VALUE);
	return (FALSE);
}

static t_bool	parsing_colors_format(char *color)
{
	color += 2;
	if (l_isnum(*color) == TRUE)
		while (l_isnum(*color) == TRUE)
			color++;
	else
		return (FAILURE);
	if (*color == ',')
		color++;
	if (l_isnum(*color) == TRUE)
		while (l_isnum(*color) == TRUE)
			color++;
	else
		return (FAILURE);
	if (*color == ',')
		color++;
	if (l_isnum(*color) == TRUE)
		while (l_isnum(*color) == TRUE)
			color++;
	else
		return (FAILURE);
	if (*color == '\0')
		return (SUCCESS);
	return (FAILURE);
}

t_bool			parsing_color(char *color, int curr_line)
{
	int r_clr;
	int g_clr;
	int b_clr;

	if (parsing_colors_format(color) == FALSE)
		return (print_color_err(ERR_COLOR_FORMAT, curr_line));
	color += 2;
	r_clr = l_atoi(color);
	while (l_isnum(*color) == TRUE)
		color++;
	if (*color == ',')
		color++;
	g_clr = l_atoi(color);
	while (l_isnum(*color) == TRUE)
		color++;
	if (*color == ',')
		color++;
	b_clr = l_atoi(color);
	if (!(r_clr >= 0 && r_clr <= 255
	&&	g_clr >= 0 && g_clr <= 255
	&&	b_clr >= 0 && b_clr <= 255))
		return (print_color_err(ERR_COLOR_VALUE, curr_line));
	return (TRUE);
}
