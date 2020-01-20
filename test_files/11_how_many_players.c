/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_how_many_players.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:37:25 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/17 12:46:38 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		how_many_players(char *line)
{
	int count;

	count = 0;
	if (line)
		while (*line)
		{
			if (l_c_finder(*line, "NSEW") == TRUE)
				count++;
			line++;
		}
	return (count);
}

int		main(int argc, char **argv)
{
	int	arg;

	if (argc < 2)
	return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		printf("%d\n", how_many_players("10111001N1010110011"));
	else if (arg == 2)
		printf("%d\n", how_many_players("10111001S1010110011"));
	else if (arg == 3)
		printf("%d\n", how_many_players("10111001E1010110011"));
	else if (arg == 4)
		printf("%d\n", how_many_players("10111001W1010110011"));
	else if (arg == 5)
		printf("%d\n", how_many_players("10111001N101N0110011"));
	else if (arg == 6)
		printf("%d\n", how_many_players("101110011010110011"));
	else if (arg == 7)
		printf("%d\n", how_many_players("10111N001N101N01100NNNNN11"));
	else if (arg == 8)
		printf("%d\n", how_many_players(NULL));
	return (0);
}
