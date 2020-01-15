/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:41:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/15 11:49:16 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sig	print_errno(void)
{
	l_putstr("Error\n");
	l_putstr(strerror(errno));
	return (ERR_ERRNO);
}
