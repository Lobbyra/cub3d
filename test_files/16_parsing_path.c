/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_parsing_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:20:47 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/21 11:08:46 by jecaudal         ###   ########.fr       */
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
		if (parsing_path("S ./Makefile") == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 2)
	{
		/*SUPPOSED TRUE*/
		if (parsing_path("NO ./Makefile") == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 3)
	{
		/*SUPPOSED FALSE*/
		if (parsing_path("SO ./DOES_NOT_EXIST") == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 4)
	{
		/*SUPPOSED TRUE*/
		if (parsing_path("WE ./Makefile") == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 5)
	{
		/*SUPPOSED TRUE*/
		if (parsing_path("EA /dev/ptyq8") == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	return (0);
}
