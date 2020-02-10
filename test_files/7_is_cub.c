/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_is_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:25:09 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/22 09:39:50 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_cub(char *path)
{
	t_bool	ret;
	char	*temp;

	ret = FALSE;
	temp = l_strcut(path, l_strlen(path) - 4);
	if (l_strcmp(temp, ".cub") == 0)
		ret = TRUE;
	free(temp);
	return (ret);
}

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
	else if (arg == 2)
	{
		path = "./oui/com/lobbyra/mapcub";
		if (is_cub(path) == TRUE)
			printf("%s -> TRUE\n", path);
		else
			printf("%s -> FALSE\n", path);
	}
	else if (arg == 3)
	{
		path = "./oui/com/lobbyra/map.ceb";
		if (is_cub(path) == TRUE)
			printf("%s -> TRUE\n", path);
		else
			printf("%s -> FALSE\n", path);
	}
	return (0);
}
