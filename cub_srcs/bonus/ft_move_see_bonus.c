/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_see_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 14:04:30 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/29 10:51:29 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_move_f_b(t_cub3d *game)
{
	if (game->press_w == 1)
	{
		game->posy += game->diry * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy -= game->diry * game->movespeed;
		game->posx += game->dirx * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx -= game->dirx * game->movespeed;
	}
	if (game->press_s == 1)
	{
		game->posy -= game->diry * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy += game->diry * game->movespeed;
		game->posx -= game->dirx * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx += game->dirx * game->movespeed;
	}
}

void		ft_move_r_l(t_cub3d *game)
{
	if (game->press_a == 1)
	{
		game->posy -= game->planey * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy += game->planey * game->movespeed;
		game->posx -= game->planex * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx += game->planex * game->movespeed;
	}
	if (game->press_d == 1)
	{
		game->posy += game->planey * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy -= game->planey * game->movespeed;
		game->posx += game->planex * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx -= game->planex * game->movespeed;
	}
}

void		ft_see_l(t_cub3d *game)
{
	if (game->left_arrow == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(-game->rotspeed) -
			game->diry * sin(-game->rotspeed);
		game->diry = game->olddirx * sin(-game->rotspeed) +
			game->diry * cos(-game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(-game->rotspeed) -
			game->planey * sin(-game->rotspeed);
		game->planey = game->oldplanex * sin(-game->rotspeed) +
			game->planey * cos(-game->rotspeed);
	}
}

void		ft_see_r(t_cub3d *game)
{
	if (game->right_arrow == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(game->rotspeed) - game->diry
			* sin(game->rotspeed);
		game->diry = game->olddirx * sin(game->rotspeed) +
			game->diry * cos(game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(game->rotspeed) -
			game->planey * sin(game->rotspeed);
		game->planey = game->oldplanex * sin(game->rotspeed) +
			game->planey * cos(game->rotspeed);
	}
}

int			ft_key_move(t_cub3d *game)
{
	if (game->width != 800 || game->height != 600)
	{
		ft_putstr("Error\nPlease use 800*600 resolution ");
		ft_putstr("for good display of the bonus part.\n");
		ft_exit(game, 0);
	}
	game->movespeed = 0.010;
	game->rotspeed = 0.01;
	if (game->press_shift == 1)
	{
		game->movespeed = 0.018;
		game->rotspeed = 0.012;
	}
	ft_move_f_b(game);
	ft_move_r_l(game);
	ft_see_r(game);
	ft_see_l(game);
	ft_win(game, 0, game->height / 4, NULL);
	ft_raycasting(game);
	return (1);
}
