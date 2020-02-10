/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_border_isok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:37:25 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/22 13:31:20 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	border_isok(char *line)
{
	if (line && line[0] == '1' && line[l_strlen(line) - 1] == '1')
		return (TRUE);
	return (FALSE);
}

int		main(int argc, char **argv)
{
	int	arg;

	if (argc < 2)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		if (border_isok("100010010101110011") == FALSE)
			printf("FALSE");
		else
			printf("TRUE");
	}
	if (arg == 2)
	{
		if (border_isok(NULL) == FALSE)
			printf("FALSE");
		else
			printf("TRUE");
	}
	if (arg == 3)
	{
		if (border_isok("00010010101110011") == FALSE)
			printf("FALSE");
		else
			printf("TRUE");
	}
	if (arg == 4)
	{
		if (border_isok("1000100101011100") == FALSE)
			printf("FALSE");
		else
			printf("TRUE");
	}
	if (arg == 5)
	{
		if (border_isok("101") == FALSE)
			printf("FALSE");
		else
			printf("TRUE");
	}
	if (arg == 6)
	{
		if (border_isok("10") == FALSE)
			printf("FALSE");
		else
			printf("TRUE");
	}
	if (arg == 7)
	{
		if (border_isok("11") == FALSE)
			printf("FALSE");
		else
			printf("TRUE");
	}
	return (0);
}
