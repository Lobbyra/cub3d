/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_parsing_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:36:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/24 10:08:45 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		panic(t_file *file)
{
	free_file(file);
	return (1);
}

int		main(int argc, char **argv)
{
	int		arg;
	t_file	*file;

	if (argc < 2)
	return (0);
	arg = atoi(argv[1]);
	file = init_file();
	if (arg == 1)
	{
		/*SUPPOSED TRUE*/
		if (get_file(file, "test_files/parsing_example_files/1_correct_hard.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 2)
	{
		/*SUPPOSED TRUE*/
		if (get_file(file, "test_files/parsing_example_files/2_correct.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 3)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/3_bad_ext.ceb") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 4)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/4_miss_header_info.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 5)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/5_unknow_info.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 6)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/6_bad_resolution_syntax.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 7)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/7_bad_resolution_x.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 8)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/8_bad_resolution_y.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 9)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/9_bad_color_syntax.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 10)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/10_bad_color_value_too.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 11)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/11_bad_color_value_nenough.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 12)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/12_bad_map_hole_top.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 13)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/13_bad_map_hole_bot.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 14)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/14_bad_map_hole_mid.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 15)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/15_bad_map_hole_mid2.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 16)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/16_no_map.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 17)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "test_files/parsing_example_files/17_empty_file.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 18)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "does_not_exist.cub") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	else if (arg == 19)
	{
		/*SUPPOSED FALSE*/
		if (get_file(file, "/dev/auditpipe") == FALSE)
			return (panic(file));
		if (parsing_file(file) == FALSE)
			return (panic(file));
		print_t_file(file);
	}
	free_file(file);
	return (0);
}
