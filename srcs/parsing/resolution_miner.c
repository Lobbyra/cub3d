/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_miner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:12:10 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/08 14:09:37 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Res[0] -> x
** Res[1] -> y
*/

int	*resolution_miner(char *raw_res)
{
	int *resolution;

	if (!raw_res)
		return (NULL);
	if (!(resolution = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	raw_res += 2;
	resolution[0] = l_atoi(raw_res);
	while (l_isspace(*raw_res) == TRUE)
		raw_res++;
	while (l_isnum(*raw_res) == TRUE)
		raw_res++;
	raw_res++;
	resolution[1] = l_atoi(raw_res);
	return (resolution);
}
