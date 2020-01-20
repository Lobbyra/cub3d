/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_parsing_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:15:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/20 10:56:13 by jecaudal         ###   ########.fr       */
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
		/*SUPPOSED FALSE*/
		if (parsing_color("C 224,125,365", 254) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}
	else if (arg == 2)
	{
		/*SUPPOSED TRUE*/
		if (parsing_color("C 2,15,3", 5) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}
	else if (arg == 3)
	{
		/*SUPPOSED TRUE*/
		if (parsing_color("C 255,1,3", 98) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}
	else if (arg == 4)
	{
		/*SUPPOSED TRUE*/
		if (parsing_color("C 1,255,3", 101) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}
	else if (arg == 5)
	{
		/*SUPPOSED TRUE*/
		if (parsing_color("C 1,1,255", 9) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}
	else if (arg == 6)
	{
		/*SUPPOSED TRUE*/
		if (parsing_color("C 255,1,3", 25) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}
	else if (arg == 7)
	{
		/*SUPPOSED FALSE*/
		if (parsing_color("C 255,,3", 19) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}
	else if (arg == 8)
	{
		/*SUPPOSED FALSE*/
		if (parsing_color("C 255,45", 56) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}
	else if (arg == 9)
	{
		/*SUPPOSED TRUE*/
		if (parsing_color("F 255,45,25", 157) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}else if (arg == 10)
	{
		/*SUPPOSED FALSE*/
		if (parsing_color("F 2555,45,25", 228) == TRUE)
			printf("TRUE");
		else
			printf("FALSE");
	}
	return (0);
}
