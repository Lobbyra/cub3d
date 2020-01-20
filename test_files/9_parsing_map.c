/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_parsing_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:44:23 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/17 13:59:13 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int	arg;

	if (argc < 2)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		/*SUPPOSED TRUE*/
		if (parsing_map("111111\n100011\n101N11\n101001\n100001\n111111", 10) == TRUE)
			ft_printf("TRUE");
	}
	else if (arg == 2)
	{
		/*SUPPOSED FALSE HOLED line 25*/
		if (parsing_map("111101111\n1100000001\n100010110111\n10010010111\n111111111", 25) == TRUE)
			ft_printf("TRUE");
	}
	else if (arg == 3)
	{
		/*SUPPOSED FALSE PLAYER 404*/
		if (parsing_map("111111\n100011\n101011\n101001\n100001\n111111", 2547) == TRUE)
			ft_printf("TRUE");
	}
	else if (arg == 4)
	{
		/*SUPPOSED FALSE PLAYER DUP line 4*/
		if (parsing_map("111111\n10N011\n101011\n101BNN1\n100001\n111111", 1) == TRUE)
			ft_printf("TRUE");
	}
	else if (arg == 5)
	{
		/*SUPPOSED TRUE*/
		if (parsing_map("11111111\n11111111111\n11000011000111\n110N00011000111111111\n110000011001\n11000001101\n11111111111111", 1) == TRUE)
			ft_printf("TRUE");
	}
	return (0);
}
