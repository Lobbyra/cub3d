/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:29:45 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/17 12:00:27 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	lmlx_destroy_image(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
}

void	lmlx_push_img(t_img *img)
{
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
}

t_img	*lmlx_new_image(void *mlx_ptr, void *win_ptr, int width, int height)
{
	t_img	*new;
	int		trsh;
	int		bpp;
	int		endian;

	bpp = CUB_BPP;
	endian = 1;
	if (!(new = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	new->width = width;
	new->height = height;
	new->mlx_ptr = mlx_ptr;
	new->win_ptr = win_ptr;
	if (!(new->img_ptr = mlx_new_image(mlx_ptr, width, height)))
	{
		free(new);
		return (NULL);
	}
	new->data_ptr = (int*)mlx_get_data_addr(new->img_ptr, &bpp, &trsh, &endian);
	return (new);
}
