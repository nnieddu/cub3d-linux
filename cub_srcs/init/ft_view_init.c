/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:08:55 by ninieddu          #+#    #+#             */
/*   Updated: 2020/10/02 11:31:02 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_view_init_next(t_cub3d *game)
{
	if (game->dir_player == 'E')
	{
		game->dirx = 1.0;
		game->diry = 0.0;
		game->planex = 0.0;
		game->planey = 0.66;
	}
	if (game->dir_player == 'W')
	{
		game->dirx = -1.0;
		game->diry = 0.0;
		game->planex = 0.0;
		game->planey = -0.66;
	}
}

void		ft_view_init(t_cub3d *game)
{
	if (game->dir_player == 'N')
	{
		game->dirx = 0.0;
		game->diry = -1.0;
		game->planex = 0.66;
		game->planey = 0.0;
	}
	if (game->dir_player == 'S')
	{
		game->dirx = 0.0;
		game->diry = 1.0;
		game->planex = -0.66;
		game->planey = 0.0;
	}
	ft_view_init_next(game);
	game->posx += 0.5;
	game->posy += 0.5;
}
