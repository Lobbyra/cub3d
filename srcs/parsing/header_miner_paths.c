/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_miner_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:54:18 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 12:14:30 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l_libc.h"

char	*header_miner_paths(char *raw_paths)
{
	char	*new;

	if (raw_paths && l_strncmp("S ", raw_paths, 2) == 0)
	{
		if (!(new = (char*)malloc(sizeof(char) * l_strlen(raw_paths) - 2 + 1)))
			return (NULL);
		l_memcpy_n(new, &raw_paths[2], l_strlen(&raw_paths[2]));
		new[l_strlen(&raw_paths[2])] = '\0';
	}
	else if (raw_paths)
	{
		if (!(new = (char*)malloc(sizeof(char) * l_strlen(raw_paths) - 3 + 1)))
			return (NULL);
		l_memcpy_n(new, &raw_paths[3], l_strlen(&raw_paths[3]));
		new[l_strlen(&raw_paths[3])] = '\0';
	}
	else
		return (NULL);
	return (new);
}
