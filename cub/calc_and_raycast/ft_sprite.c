/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 13:59:02 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/25 17:54:59 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_alloc_sprite_order(t_cub3d *game)
{
	if (!(game->sp_order = (int *)malloc(sizeof(int) * (game->sp_nbr + 1))))
		ft_exit(game, 1);
	if (!(game->sp_dist = (double *)malloc(sizeof(double) *
		(game->sp_nbr + 1))))
		ft_exit(game, 1);
	game->sp_order[game->sp_nbr] = '\0';
	game->sp_dist[game->sp_nbr] = '\0';
}

void		ft_calculate_sort_dist(t_cub3d *game)
{
	int			i;
	int			j;
	int			tmp;
	double		tmp1;

	j = 0;
	i = -1;
	while (++i < game->sp_nbr)
	{
		j = i - 1;
		while (++j < game->sp_nbr)
		{
			if (game->sp_dist[i] < game->sp_dist[j])
			{
				tmp = game->sp_order[i];
				game->sp_order[i] = game->sp_order[j];
				game->sp_order[j] = tmp;
				tmp1 = game->sp_dist[i];
				game->sp_dist[i] = game->sp_dist[j];
				game->sp_dist[j] = tmp1;
				i = -1;
				j = game->sp_nbr;
			}
		}
	}
}

void		ft_calculate_sprite_dist(t_cub3d *game, t_sprites *sprites, int k)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == '2')
			{
				sprites[k].y = i + 0.5;
				sprites[k++].x = j + 0.5;
			}
	}
	i = -1;
	while (++i < game->sp_nbr)
	{
		game->sp_order[i] = i;
		game->sp_dist[i] = ((game->posx - sprites[i].x) * (game->posx -
			sprites[i].x) + (game->posy - sprites[i].y) * (game->posy -
			sprites[i].y));
	}
	ft_calculate_sort_dist(game);
}

void		ft_calculate_sprite_next(t_cub3d *game)
{
	if (game->drawstarty < 0)
		game->drawstarty = 0;
	game->drawendy = game->sp_h / 2 + game->height / 2;
	if (game->drawstarty >= game->height)
		game->drawstarty = game->height - 1;
	game->sp_w = game->height / game->transy;
	game->drawstartx = -game->sp_w / 2 + game->sp_screen;
	if (game->drawstartx < 0)
		game->drawstartx = 0;
	game->drawendx = game->sp_w / 2 + game->sp_screen;
	if (game->drawendx >= game->width)
		game->drawendx = game->width - 1;
}

void		ft_calculate_sprite(t_cub3d *game, int x)
{
	int			k;
	t_sprites	*sprites;

	k = 0;
	if (!(sprites = malloc(sizeof(t_sprites) * (game->sp_nbr + 1))))
		ft_exit(game, 1);
	ft_calculate_sprite_dist(game, sprites, k);
	game->sp_x = sprites[game->sp_order[x]].x - game->posx;
	game->sp_y = sprites[game->sp_order[x]].y - game->posy;
	game->inv_det = 1.0 / (game->planex * game->diry - game->dirx *
		game->planey);
	game->transx = game->inv_det * (game->diry * game->sp_x - game->dirx
		* game->sp_y);
	game->transy = game->inv_det * (-game->planey * game->sp_x +
		game->planex * game->sp_y);
	game->sp_screen = ((game->width / 2) * (1 + game->transx /
		game->transy));
	game->sp_h = game->height / game->transy;
	game->drawstarty = -game->sp_h / 2 + game->height / 2;
	ft_calculate_sprite_next(game);
	ft_memdel((void*)&sprites);
}
