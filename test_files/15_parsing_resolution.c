/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_parsing_resolution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:15:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/20 13:11:28 by jecaudal         ###   ########.fr       */
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
		if (parsing_resolution("R 1920 1080", 2) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 2)
	{
		/*SUPPOSED FALSE*/
		if (parsing_resolution("R 1920,1080", 23) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 3)
	{
		/*SUPPOSED FALSE*/
		if (parsing_resolution("R -1920 1080", 212) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 4)
	{
		/*SUPPOSED FALSE*/
		if (parsing_resolution("R -1920 -1080", 9) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 5)
	{
		/*SUPPOSED FALSE*/
		if (parsing_resolution("R 1920 -1080", 3) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 6)
	{
		/*SUPPOSED FALSE*/
		if (parsing_resolution("R 1920", 3) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 7)
	{
		/*SUPPOSED FALSE*/
		if (parsing_resolution("R ", 3) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	else if (arg == 8)
	{
		/*SUPPOSED FALSE*/
		if (parsing_resolution("R 1 1", 3) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
		return (1);
	}
	return (0);
}
