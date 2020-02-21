/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:50:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/19 14:57:16 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	panic_window(t_stock *stock)
{
	free_stock(stock);
	l_printf("Error\n");
	l_printf("The window could not be created. Try to restart the program.\n");
	return (1);
}

int			main(int argc, char **argv)
{
	void	*win_ptr;
	t_info	*info;
	t_stock	*s;

	if (argc < 2 || !(info = parsing(argv[1])))
		return (1);
	if (!(s = init_stock(info)))
		return (1);
	free_info(info);
	s->mlx_ptr = mlx_init();
	if (!(win_ptr = mlx_new_window(s->mlx_ptr, s->w, s->h, "cub3d")))
		return (panic_window(s));
	init_stock_xpm(s);
	s->win_ptr = win_ptr;
	raycasting(s);
	return (0);
}
