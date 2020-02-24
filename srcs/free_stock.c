/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:48:34 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/24 15:19:49 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_stock(t_stock *stock)
{
	l_freestrs(stock->map);
	lmlx_free_t_img(stock->text_n);
	lmlx_free_t_img(stock->text_s);
	lmlx_free_t_img(stock->text_e);
	lmlx_free_t_img(stock->text_sp);
	if (stock->n_path)
		free(stock->n_path);
	if (stock->s_path)
		free(stock->s_path);
	if (stock->e_path)
		free(stock->e_path);
	if (stock->w_path)
		free(stock->w_path);
	if (stock->sprite_path)
		free(stock->sprite_path);
	mlx_destroy_window(stock->mlx_ptr, stock->win_ptr);
}
