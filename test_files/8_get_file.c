/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_get_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:09:14 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/15 14:04:52 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int	arg;
	t_file *file;

	if (argc < 2)
		return (0);
	arg = atoi(argv[1]);
	file = init_file();
	if (arg == 1)
	{
		get_file(file, "test_files/_8_a_bad_line.cub");
		print_t_file(file);
	}
	else if (arg == 2)
	{
		get_file(file, "test_files/_8_correct_file.cub");
		print_t_file(file);
	}
	else if (arg == 3)
	{
		get_file(file, "test_files/_8_good_but_missings.cub");
		print_t_file(file);
	}
	else if (arg == 4)
	{
		get_file(file, "test_files/_8_wrong_ext.ceb");
		print_t_file(file);
	}
	else if (arg == 5)
	{
		get_file(file, "test_files/_8_does_not_exist.cub");
		print_t_file(file);
	}
	return (0);
}
