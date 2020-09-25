/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:26:45 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/23 12:07:17 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_check_line_next(t_cub3d *game, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'E' ||
		game->map[i][j] == 'W' || game->map[i][j] == 'S')
	{
		game->map_spawn++;
		if (game->map_spawn == 1)
			game->dir_player = game->map[i][j];
		game->posx = (double)j;
		game->posy = (double)i;
	}
	if (game->map[i][j] == ' ')
		game->map[i][j] = '1';
	if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->
		map[i][j] != '2' && game->map[i][j] != 'N' && game->map[i][j]
		!= 'S' && game->map[i][j] != 'E' && game->map[i][j] != 'W')
	{
		ft_putstr("Error\nMap error, a space need to be out of the map or");
		ft_putstr(" surrounded by '1'.\n");
		ft_exit(game, 0);
	}
}

void		ft_check_line(t_cub3d *game, int i, int j)
{
	while (game->map[i][j])
	{
		ft_check_line_next(game, i, j);
		if (game->map[i][j++] == '2')
			game->sp_nbr++;
	}
}

void		ft_all_line(t_cub3d *game, int i, int j)
{
	i = 0;
	j = -1;
	while (game->map[1][++j])
	{
		if (game->map[1][j] == '0' && game->map[0][j] != '1')
		{
			ft_putstr("Error\nMap error : missing '1' at the begining ");
			ft_putstr("of line.\n");
			ft_exit(game, 0);
		}
	}
	while (game->map[i])
	{
		ft_check_line(game, i, 0);
		i++;
	}
}

void		ft_check_map_error_next(t_cub3d *game, int i, int j)
{
	ft_check_map_closed_left(game, 0, 0, '1');
	i = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == ' ')
			{
				ft_putstr("Error\nMap error, a space need to be out");
				ft_putstr(" of the map or surrounded by '1'.\n");
				ft_exit(game, 0);
			}
		}
	}
	ft_all_line(game, i, 0);
	ft_alloc_sprite_order(game);
	if (game->map_spawn != 1)
	{
		ft_putstr("Error\nMany or no spawn point in the map (N,S,E,W)\n");
		ft_exit(game, 0);
	}
}

void		ft_check_map_error(t_cub3d *game, int i, int j)
{
	while (game->map[i][j] != '1')
	{
		if (game->map[i][j] == '\0')
		{
			i--;
			j = 0;
		}
		if (game->map[i][j] == ' ')
		{
			game->map[i][j] = '1';
			j++;
		}
	}
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			ft_check_in_map_space(game, i, j);
	}
	ft_check_map_error_next(game, i, j);
}
