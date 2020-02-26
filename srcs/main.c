/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:50:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/26 09:44:32 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		panic_window(t_stock *stock)
{
	free_stock(stock);
	l_printf("Error\n");
	l_printf("The window could not be created. Try to restart the program.\n");
	return (1);
}

static t_bool	is_right_argvs(int argc, char **argv)
{
	if ((argc == 2 && l_strcmp(argv[1], "-save") == 0) || argc < 2)
	{
		l_printf("Error\nMap file is missing.");
		return (FALSE);
	}
	else if ((argc == 2 && l_strcmp(argv[1], "-save") == 0) ||
	(argc == 3 && l_strcmp(argv[1], "-save") != 0) || argc > 3)
	{
		l_printf("Error\nToo many arguments.\n");
		l_printf("USAGE -> ./cub3d [-save] *.cub\n");
		return (FALSE);
	}
	else if (l_strcmp("--help", argv[1]) == 0)
	{
		l_printf("USAGE -> ./cub3d [-save] *.cub\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_info	*main_init_info(char **argv)
{
	if (l_strcmp(argv[1], "-save") == 0)
		return (parsing(argv[2]));
	else
		return (parsing(argv[1]));
	return (NULL);
}

int				main(int argc, char **argv)
{
	void	*win_ptr;
	t_info	*info;
	t_stock	*s;

	if (is_right_argvs(argc, argv) == FALSE)
		return (1);
	info = main_init_info(argv);
	if (info == NULL || !(s = init_stock(info)))
		return (1);
	free_info(info);
	s->mlx_ptr = mlx_init();
	if (!(win_ptr = mlx_new_window(s->mlx_ptr, s->w, s->h, "cub3d")))
		return (panic_window(s));
	s->win_ptr = win_ptr;
	init_stock_xpm(s);
	if (is_xpm_inited(s) == FALSE)
		cub_exit(s);
	if (init_stock_sprites(s) == 1)
		cub_exit(s);
	if (l_strcmp(argv[1], "-save") != 0)
		raycasting(s);
	else
		save_bmp(s);
	return (0);
}

void __attribute__((destructor)) f()
{
	l_printf("[LEAKS CHECKING]\n");
	getchar();
	{}
}
