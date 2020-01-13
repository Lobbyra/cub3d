/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_detect_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:29:52 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/13 15:12:44 by jecaudal         ###   ########.fr       */
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
		print_t_sig(detect_line(""));
	else if (arg == 2)
		print_t_sig(detect_line("1 0 1  0 1 1 0 1 0 2 2 1 1  N 0 0"));
	else if (arg == 3)
		print_t_sig(detect_line("1 0 1  0 1 1 0 Y 1 0 2 2 1 1  N 0 0"));
	else if (arg == 4)
		print_t_sig(detect_line("R 1920 1080"));
	else if (arg == 5)
		print_t_sig(detect_line("NO /coucou/les/petits/fours"));
	else if (arg == 6)
		print_t_sig(detect_line("SO /home/ubuntu"));
	else if (arg == 7)
		print_t_sig(detect_line("EA ./path/to/your/file"));
	else if (arg == 8)
		print_t_sig(detect_line("WE ./paf/tou/yourr/fillile"));
	else if (arg == 9)
		print_t_sig(detect_line("S ./paf/tou/yourr/fillile"));
	else if (arg == 10)
		print_t_sig(detect_line("C 254,2,36"));
	else if (arg == 11)
		print_t_sig(detect_line("F 68,9,105"));
	return (0);
}
