/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stock_checkers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:41:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 16:03:24 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_xpm_inited(t_stock *stock)
{
	if (stock->zbuffer == NULL)
	{
		l_printf("Error\n");
		l_printf(ERR_MSG_MALLOC);
		return (FALSE);
	}
	if (stock->text_n == NULL || stock->text_s == NULL ||
		stock->text_e == NULL || stock->text_w == NULL ||
		stock->text_sp == NULL)
	{
		l_printf("Error\n");
		if (stock->text_n == NULL)
			l_printf(ERR_XPM_MSG_NORTH);
		if (stock->text_s == NULL)
			l_printf(ERR_XPM_MSG_SOUTH);
		if (stock->text_e == NULL)
			l_printf(ERR_XPM_MSG_EAST);
		if (stock->text_w == NULL)
			l_printf(ERR_XPM_MSG_WEST);
		if (stock->text_sp == NULL)
			l_printf(ERR_XPM_MSG_SPRITE);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	is_infocpy_inited(t_stock *stock)
{
	if (stock->n_path == NULL || stock->s_path == NULL ||
		stock->e_path == NULL || stock->w_path == NULL ||
		stock->sprite_path == NULL || stock->map == NULL)
	{
		l_printf("Error\n");
		l_printf(ERR_XPM_MSG_NORTH);
		if (stock->n_path != NULL)
			free(stock->n_path);
		else if (stock->s_path != NULL)
			free(stock->s_path);
		else if (stock->e_path != NULL)
			free(stock->e_path);
		else if (stock->w_path != NULL)
			free(stock->w_path);
		else if (stock->sprite_path != NULL)
			free(stock->sprite_path);
		else if (stock->map != NULL)
			l_freestrs(stock->map);
		return (FALSE);
	}
	return (TRUE);
}
