/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_header_miner_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:32:27 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 10:57:37 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int arg;

	if (argc < 2)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		printf("\"254,6,89\" is 16647769 and ret = %d", header_miner_color("254,6,89"));
	if (arg == 2)
		printf("\"0,0,0\" is 0 and ret = %d", header_miner_color("0,0,0"));
	if (arg == 3)
		printf("\"255,255,255\" is 16777215 and ret = %d", header_miner_color("255,255,255"));
	if (arg == 4)
		printf("If you can read me its right");
	return (0);
}
