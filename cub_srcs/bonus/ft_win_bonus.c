/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:16:12 by ninieddu          #+#    #+#             */
/*   Updated: 2020/10/02 13:17:29 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_win(t_cub3d *game, void *v, int *vic_data, int x)
{
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
		"./textures/vic.xpm", &game->sp_width, &game->sp_width)))
			ft_exit_texture(game);
		if (!(vic_data = (int *)mlx_get_data_addr(v,
		&game->bits_per_pixel, &game->size_line, &game->endian)))
			ft_exit_texture(game);
		while (x < 300)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, v, 0, 0);
			x++;
		}
		system("#/bin/bash \n aplay ./textures/wow.wav \n exit");
		mlx_destroy_image(game->mlx_ptr, v);
		ft_exit(game, 0);
	}
}
