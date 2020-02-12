/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:29:45 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/11 11:50:36 by jecaudal         ###   ########.fr       */
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
	return (new);
}

void	lmlx_pixel_put(t_img *img, int rgb, int x, int y)
{
	int		*edit_img;
	int		bpp = CUB_BPP;
	int		endian = 1;

	edit_img = (int*)mlx_get_data_addr(img->img_ptr, &bpp, &(img->width), &endian);
	if (((img->width / 4) * y + x <= img->width * img->height)
	&& x < img->width && y < img->height && x > 0 && y > 0)
		*(edit_img + ((img->width / 4) * y) + x) = rgb;
}
