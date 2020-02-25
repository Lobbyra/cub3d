/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:47:08 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/25 16:57:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		print_img_err(t_stock *stock)
{
	l_printf("Error\n");
	l_printf("Image in render.c render() could not be Created.\n");
	l_printf("You can try to restart the program.\n");
	cub_exit(stock);
}

static void		panic_save(t_stock *stock)
{
	l_printf("Error\n");
	l_printf("Saving bmp file could not be created.\n");
	l_printf("Check rights and restart cub3d.\n");
	cub_exit(stock);
}

static t_bmp	init_bmp(t_stock *s)
{
	t_bmp bmp;

	bmp.magic[0] = 'B';
	bmp.magic[1] = 'M';
	bmp.magic[2] = '\0';
	bmp.app_spe = 0;
	bmp.data_offset = 54;
	bmp.size_dib = 40;
	bmp.w = s->w;
	bmp.h = s->h;
	bmp.planes = 1;
	bmp.bpp = 32;
	bmp.size_file = bmp.data_offset + ((bmp.w * bmp.h) * 4);
	bmp.data_ptr = s->img->data_ptr;
	bmp.padding_trash = 0;
	return (bmp);
}

static void		write_file(int fd, t_bmp bmp)
{
	int x;
	int y;
	int	mix_planes_bpp;

	y = bmp.h - 1;
	mix_planes_bpp = bmp.bpp;
	mix_planes_bpp = (mix_planes_bpp << 16) + bmp.planes;
	l_putstr_fd(bmp.magic, fd);
	write(fd, &bmp.size_file, 4);
	write(fd, &bmp.app_spe, 4);
	write(fd, &bmp.data_offset, 4);
	write(fd, &bmp.size_dib, 4);
	write(fd, &bmp.w, 4);
	write(fd, &bmp.h, 4);
	write(fd, &mix_planes_bpp, 4);
	write(fd, &bmp.padding_trash, 8);
	write(fd, &bmp.padding_trash, 8);
	write(fd, &bmp.padding_trash, 8);
	while (y >= 0)
	{
		x = 0;
		while (x < bmp.w)
			write(fd, &(bmp.data_ptr[(y * bmp.w) + x++]), 4);
		y--;
	}
}

void			save_bmp(t_stock *stock)
{
	int		fd;
	t_img	*img;
	t_bmp	bmp;

	if ((fd = open("save.bmp", O_RDWR | O_CREAT, S_IRWXU)) == -1)
		panic_save(stock);
	player_update(stock);
	img = lmlx_new_image(stock->mlx_ptr, stock->win_ptr, stock->w, stock->h);
	if (!(stock->img = img))
		print_img_err(stock);
	draw_background(stock->img, stock->ceiling_color, stock->floor_color);
	perform_raycasting(stock);
	draw_sprites(stock);
	bmp = init_bmp(stock);
	write_file(fd, bmp);
	lmlx_destroy_image(img);
	close(fd);
	cub_exit(stock);
}
