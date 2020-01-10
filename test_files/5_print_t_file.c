/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_print_t_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:57:20 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/10 15:11:16 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int		arg;
	t_file	*file;

	if (argc < 2)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		file = init_file();
		print_t_file(file);
		free_file(file);
	}
	return (0);
}
