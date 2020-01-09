/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_header_miner_res.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:12:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/09 13:33:33 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int	*tab;
	int	arg;

	if (argc < 2)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		tab = header_miner_res("R 1920 501");
		printf("res of \"R 1920 501\" is %d %d", tab[0], tab[1]);
	}
	if (arg == 2)
	{
		tab = header_miner_res("R 0 0");
		printf("res of \"R 0 0\" is %d %d", tab[0], tab[1]);
	}
	if (arg == 3)
	{
		tab = header_miner_res(NULL);
		printf("res of null");
	}
	if (arg == 4)
	{
		tab = header_miner_res("R -15477 -15477");
		printf("res of \"R -15477 -15477\" is %d %d", tab[0], tab[1]);
	}
	return (0);
}
