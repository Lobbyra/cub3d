/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:27:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/13 14:59:35 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Take a string readed in parameter and return code accord.
** See defines for more details.
*/

t_sig	detect_line(char *str)
{
	if (!str)
		return (LSIG_EMPTY);
	else if (l_strncmp(str, "", 1) == 0)
		return (LSIG_EMPTY);
	else if (l_strncmp(str, "R ", 2) == 0)
		return (LSIG_RESOLUTION);
	else if (l_strncmp(str, "NO ", 3) == 0)
		return (LSIG_NPATH);
	else if (l_strncmp(str, "SO ", 3) == 0)
		return (LSIG_SPATH);
	else if (l_strncmp(str, "EA ", 3) == 0)
		return (LSIG_EPATH);
	else if (l_strncmp(str, "WE ", 3) == 0)
		return (LSIG_WPATH);
	else if (l_strncmp(str, "S ", 2) == 0)
		return (LSIG_SPRITE_PATH);
	else if (l_strncmp(str, "F ", 2) == 0)
		return (LSIG_FLOOR_CLR);
	else if (l_strncmp(str, "C ", 2) == 0)
		return (LSIG_CEILING_CLR);
	else if (l_strbool(l_strclean(str, " "), &is_map) == TRUE)
		return (LSIG_MAP);
	return (LSIG_UNKNOW);
}
