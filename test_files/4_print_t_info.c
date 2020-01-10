/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_print_t_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:57:20 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/10 15:05:00 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	int		arg;
	t_info	*info;

	if (argc < 2)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		info = init_info();
		info->map = l_split("101110011100\n01011001010101\n010010101\n", "\n");
		print_t_info(info);
		free_info(info);
	}
	return (0);
}
