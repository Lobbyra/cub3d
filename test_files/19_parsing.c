/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:11:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/08 14:42:26 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int		arg;
	t_info	*info;

	if (argc < 2)
		return (0);
	info = NULL;
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		/*SUPPOSED TRUE*/
		if ((info = parsing("test_files/parsing_example_files/1_correct_hard.cub")) == NULL)
			return (1);
		print_t_info(info);
	}
	else if (arg == 2)
	{
		/*SUPPOSED TRUE*/
		if ((info = parsing("test_files/parsing_example_files/2_correct.cub")) == NULL)
			return (1);
		print_t_info(info);
	}
	else if (arg == 3)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/3_bad_ext.ceb")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 4)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/4_miss_header_info.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 5)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/5_unknow_info.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 6)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/6_bad_resolution_syntax.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 7)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/7_bad_resolution_x.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 8)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/8_bad_resolution_y.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 9)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/9_bad_color_syntax.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 10)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/10_bad_color_value_too.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 11)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/11_bad_color_value_nenough.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 12)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/12_bad_map_hole_top.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 13)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/13_bad_map_hole_bot.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 14)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/14_bad_map_hole_mid.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 15)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/15_bad_map_hole_mid2.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 16)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/16_no_map.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 17)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("test_files/parsing_example_files/17_empty_file.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 18)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("does_not_exist.cub")))
			return (1);
		if (info)
			print_t_info(info);
	}
	else if (arg == 19)
	{
		/*SUPPOSED FALSE*/
		if ((info = parsing("/dev/auditpipe")))
			return (1);
		if (info)
			print_t_info(info);
	}
	if (info)
		free_info(info);
	return (0);
}
