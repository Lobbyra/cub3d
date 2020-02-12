/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:53:01 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/12 15:33:52 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_img_err(t_stock *stock)
{
	l_printf("Error\n");
	l_printf("Image in render.c render() could not be Created.\n");
	l_printf("You can try to restart the program.\n");
	cub_exit(stock);
}

static void draw_debug(t_stock *stock)
{
	if (stock->key & KEY_UP)
		mlx_string_put(stock->mlx_ptr, stock->win_ptr, 10, 10, COLOR_W, "Z");
	if (stock->key & KEY_DOWN)
		mlx_string_put(stock->mlx_ptr, stock->win_ptr, 20, 10, COLOR_W, "S");
	if (stock->key & KEY_RIGHT)
		mlx_string_put(stock->mlx_ptr, stock->win_ptr, 30, 10, COLOR_W, "D");
	if (stock->key & KEY_LEFT)
		mlx_string_put(stock->mlx_ptr, stock->win_ptr, 40, 10, COLOR_W, "Q");
	if (stock->key & KEY_ROTL)
		mlx_string_put(stock->mlx_ptr, stock->win_ptr, 50, 10, COLOR_W, "<-");
	if (stock->key & KEY_ROTR)
		mlx_string_put(stock->mlx_ptr, stock->win_ptr, 70, 10, COLOR_W, "->");
}

int		render(void *param)
{
	t_stock	*stock;
	t_img	*img;

	stock = (t_stock*)param;
	img = lmlx_new_image(stock->mlx_ptr, stock->win_ptr, stock->w, stock->h);
	if (!(stock->img = img))
		print_img_err(stock);
	player_update(stock);
	perform_raycasting(stock);
	lmlx_push_img(img);
	if (stock->key & KEY_DEBUG && stock->w * stock->h > 10000)
	{
		print_t_stock(stock);
		draw_debug(stock);
	}
	lmlx_destroy_image(img);
	return (0);
}
