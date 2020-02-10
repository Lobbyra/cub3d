/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:20:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/21 11:10:08 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parsing_path(char *path)
{
	int	fd;

	errno = 0;
	if (l_strncmp(path, "S ", 2) == 0)
		path += 2;
	else
		path += 3;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		l_printf("[PATH ERROR] [%s] : %s\n", path, strerror(errno));
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}
