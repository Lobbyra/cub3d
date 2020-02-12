/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:50:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/11 13:10:06 by jecaudal         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	void	*win_ptr;
	void	*mlx_ptr;
	t_info	*info;
	t_stock	*stock;

	info = NULL;
	stock = NULL;
	if (argc < 2 || !(info = parsing(argv[1])))
		return (1);
	if (!(stock = init_stock(info)))
		return (1);
	free_info(info);
	mlx_ptr = mlx_init();
	stock->mlx_ptr = mlx_ptr;
	if (!(win_ptr = mlx_new_window(mlx_ptr, stock->w, stock->h, "cub3d")))
		return (panic_window(stock));
	stock->win_ptr = win_ptr;
	raycasting(stock);
	return (0);
}
