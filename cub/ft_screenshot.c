/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 15:04:50 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/11 11:00:56 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_bitmap_image(t_cub3d *game, int fd, t_bpm2 bitinf)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bitinf, sizeof(bitinf));
	y = game->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < game->width)
		{
			ble = game->img_data[y * game->width + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
	close(fd);
}

void		ft_write_bitmap(t_bpm bitheader, int fd)
{
	write(fd, &bitheader.bitmap_type, sizeof(bitheader.bitmap_type));
	write(fd, &bitheader.file_size, sizeof(bitheader.file_size));
	write(fd, &bitheader.reserved1, sizeof(bitheader.reserved1));
	write(fd, &bitheader.reserved2, sizeof(bitheader.reserved2));
	write(fd, &bitheader.offset_bits, sizeof(bitheader.offset_bits));
}

void		ft_save_bitmap(char *filename, t_cub3d *game)
{
	int		fd;
	t_bpm	bitheader;
	t_bpm2	bitinf;

	ft_memcpy(&bitheader.bitmap_type, "BM", 2);
	bitheader.file_size = game->width * game->height * 4 + 54;
	bitheader.reserved1 = 0;
	bitheader.reserved2 = 0;
	bitheader.offset_bits = 0;
	bitinf.size_header = sizeof(bitinf);
	bitinf.width = game->width;
	bitinf.height = game->height;
	bitinf.planes = 1;
	bitinf.bit_count = 32;
	bitinf.compression = 0;
	bitinf.image_size = game->width * game->height * 4 + 54;
	bitinf.ppm_x = 2;
	bitinf.ppm_y = 2;
	bitinf.clr_used = 0;
	bitinf.clr_important = 0;
	fd = open(filename, O_RDONLY | O_CREAT, S_IRWXU);
	close(fd);
	fd = open(filename, O_RDWR);
	ft_write_bitmap(bitheader, fd);
	ft_bitmap_image(game, fd, bitinf);
}
