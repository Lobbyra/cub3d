/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:08:54 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/24 11:05:33 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int		arg;
	t_file	*file;
	t_info	*info;

	if (argc < 2)
	return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		/*Basic use case*/
		file = init_file();
		if (get_file(file, "test_files/parsing_example_files/2_correct.cub") == FAILURE)
		{
			free_file(file);
			return (1);
		}
		info = get_info(file);
		print_t_file(file);
		free_file(file);
		free_info(info);
	}
	else if (arg == 2)
	{
		/*Advanced use case*/
		file = init_file();
		if (get_file(file, "test_files/parsing_example_files/1_correct_hard.cub") == FAILURE)
		{
			free_file(file);
			return (1);
		}
		info = get_info(file);
		print_t_file(file);
		free_file(file);
		free_info(info);
	}
	return (0);
}
