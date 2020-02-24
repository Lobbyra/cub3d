/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:50:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 15:54:22 by jecaudal         ###   ########.fr       */
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
	s->win_ptr = win_ptr;
	init_stock_xpm(s);
	if (is_xpm_inited(s) == FALSE)
		cub_exit(s);
	if (init_stock_sprites(s) == 1)
		cub_exit(s);
	raycasting(s);
	return (0);
}
