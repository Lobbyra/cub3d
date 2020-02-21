/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:53:01 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/21 11:33:41 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** 	texture_test = mlx_xpm_file_to_image(stock->mlx_ptr, "stone.xpm", &w, &h);
**	mlx_put_image_to_window(stock->mlx_ptr, stock->win_ptr, texture_test, 0, 0);
*/

static void	print_img_err(t_stock *stock)
{
	l_printf("Error\n");
	l_printf("Image in render.c render() could not be Created.\n");
	l_printf("You can try to restart the program.\n");
	cub_exit(stock);
}

int			render(void *param)
{
	t_stock	*stock;
	t_img	*img;

	stock = (t_stock*)param;
	if (stock->key == 0)
		return (0);
	player_update(stock);
	img = lmlx_new_image(stock->mlx_ptr, stock->win_ptr, stock->w, stock->h);
	if (!(stock->img = img))
		print_img_err(stock);
	draw_background(stock->img, stock->ceiling_color, stock->floor_color);
	perform_raycasting(stock);
	lmlx_push_img(img);
	lmlx_destroy_image(img);
	return (0);
}
