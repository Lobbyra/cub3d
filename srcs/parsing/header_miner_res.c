/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_miner_res.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:12:10 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 14:05:46 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Res[0] -> x
** Res[1] -> y
*/

int	*header_miner_res(char *raw_res)
{
	int *resolution;

	if (!raw_res)
		return (NULL);
	if (!(resolution = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	resolution[0] = l_atoi(&raw_res[2]);
	while (l_isspace(*raw_res) == TRUE)
		raw_res++;
	while (l_isnum(*raw_res) == TRUE)
		raw_res++;
	raw_res++;
	resolution[1] = l_atoi(raw_res);
	return (resolution);
}
