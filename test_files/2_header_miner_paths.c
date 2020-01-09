/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_header_miner_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:07:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 12:15:11 by jecaudal         ###   ########.fr       */
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
	{
		printf("path of \"S /root/coucou/desktop\" is [%s]", header_miner_paths("S /root/coucou/desktop"));
	}
	if (arg == 2)
	{
		printf("null tester %s", header_miner_paths(NULL));
	}
	return (0);
}
