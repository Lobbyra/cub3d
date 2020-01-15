/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:31:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/15 13:37:14 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_t_err(t_err err)
{
	if (err == ERR_MEMALLOC)
		l_putstr("ERR_MEMALLOC\n");
	else if (err == ERR_UNKNOW)
		l_putstr("ERR_UNKNOW\n");
	else if (err == ERR_ERRNO)
		l_putstr("ERR_ERRNO\n");
	else if (err == ERR_NOT_CUB)
		l_putstr("ERR_NOT_CUB\n");
	else if (err == ERR_MISSING)
		l_putstr("ERR_MISSING\n");
	else if (err == ERR_DUPED_INFO)
		l_putstr("ERR_DUPED_INFO\n");
}
