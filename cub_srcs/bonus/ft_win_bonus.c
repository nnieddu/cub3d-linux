/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:16:12 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/25 18:06:07 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_win_next(t_cub3d *game, int h, int w, void *v)
{
	while (h < game->height + 256)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, v, w, h);
		h++;
	}
	h = game->height - 256;
	while (w > -game->width + 256)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, v, w, h);
		w--;
	}
	w = 0;
	while (h != -256)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, v, w, h);
		h--;
	}
	h = 250;
	while (w != game->width - 400)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, v, w, h);
		w++;
	}
	system("#/bin/bash \n aplay ./textures/wow.wav \n exit");
	ft_exit(game, 0);
}

void		ft_win(t_cub3d *game, int h, int w, int *vic_data)
{
	void	*v;

	if (((game->map[(int)(game->posy + game->diry * game->movespeed)]
	[(int)(game->posx + game->dirx * game->movespeed)] == '2') ||
	(game->map[(int)(game->posy - game->diry * game->movespeed)]
	[(int)(game->posx - game->dirx * game->movespeed)] == '2') ||
	(game->map[(int)(game->posy - game->planey * game->movespeed)]
	[(int)(game->posx - game->planex * game->movespeed)] == '2') ||
	(game->map[(int)(game->posy + game->planey * game->movespeed)]
	[(int)(game->posx + game->planex * game->movespeed)] == '2')))
	{
		if (!(v = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/win.xpm", &game->sp_width, &game->sp_width)))
			ft_exit_texture(game);
		if (!(vic_data = (int *)mlx_get_data_addr(v,
		&game->bits_per_pixel, &game->size_line, &game->endian)))
			ft_exit_texture(game);
		while (w < game->width + 256)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, v, w, 0);
			w++;
		}
		w = game->width - 256;
		ft_win_next(game, h, w, v);
	}
}
