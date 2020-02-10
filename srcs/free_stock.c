/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:48:34 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/10 14:59:53 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_stock(t_stock *stock)
{
	l_freestrs(stock->map);
	free(stock->n_path);
	free(stock->s_path);
	free(stock->e_path);
	free(stock->w_path);
	free(stock->sprite_path);
	free(stock);
}
