/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_is_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:25:09 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/15 13:18:29 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	char *path;
	int	arg;

	if (argc < 2)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		path = "./oui/com/lobbyra/map.cub";
		if (is_cub(path) == TRUE)
			printf("%s -> TRUE\n", path);
		else
			printf("%s -> FALSE\n", path);
	}
	if (arg == 2)
	{
		path = "./oui/com/lobbyra/mapcub";
		if (is_cub(path) == TRUE)
			printf("%s -> TRUE\n", path);
		else
			printf("%s -> FALSE\n", path);
	}
	return (0);
}
