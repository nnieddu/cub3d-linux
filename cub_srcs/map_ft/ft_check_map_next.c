/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:16:07 by ninieddu          #+#    #+#             */
/*   Updated: 2020/10/02 13:17:35 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_is_out_of_map(t_cub3d *game, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'E' ||
		game->map[i][j] == 'W' || game->map[i][j] == 'S'
		|| game->map[i][j] == '2')
	{
		if (game->zero != 0 && (game->map[i][j + 1] != '1'
		|| game->map[i][j - 1] != '1'))
		{
			ft_putstr("Error\nMap error : 0, 2, N, S, E, or W is ");
			ft_putstr("out of the map.\nOr new line or space in the map.\n");
			ft_exit(game, 0);
		}
		if (!(game->map[i + 1]))
		{
			ft_putstr("Error\nNew line in the map or something out.");
			ft_exit(game, 0);
		}
	}
}

void		ft_check_in_map_space(t_cub3d *game, int i, int j)
{
	if (game->map[i][j] == ' ' && (j - 1) == -1 && ((j + 1) <=
		ft_strlen(game->map[i]) && ((game->map[i][j + 1] == ' ') ||
		(game->map[i][j + 1] == '1'))))
		game->map[i][j] = '1';
	else if (game->map[i][j] == ' ' && ((j - 1) >= 0 &&
		((game->map[i][j - 1] == ' ') || ((game->map[i][j - 1] == '1')))) &&
		((j + 1) <= ft_strlen(game->map[i]) &&
		((game->map[i][j + 1] == ' ') || (game->map[i][j + 1] == '1'))))
	{
		if (((i - 1) >= 0 && game->map[i - 1] && ft_strlen(game->map[i
			- 1]) >= j && game->map[i - 1][j] == '0') || ((j - 1) >= 0 &&
			game->map[i][j - 1] == '0') || ((j + 1) <= ft_strlen(game->map[i])
			&& game->map[i][j + 1] == '0') || (game->map[i + 1] &&
			ft_strlen(game->map[i + 1]) >= j && game->map[i + 1][j] == '0'))
		{
			ft_putstr("Error\nA space and a '0' can't be in contact.");
			ft_exit(game, 0);
		}
		game->map[i][j] = '1';
	}
}

void		ft_spawn_is_closed(t_cub3d *game, int i, int j)
{
	while (game->map[++i])
	{
		while (game->map[i][++j] && i != game->maplinecount)
		{
			if ((game->map[i][j] == 'N' || game->map[i][j] == 'E' ||
			game->map[i][j] == 'W' || game->map[i][j] == 'S')
			&& (ft_strlen(game->map[i - 1]) - 1 < j
			|| ft_strlen(game->map[i + 1]) - 1 < j))
			{
				ft_putstr("Error\nMany spawn or in contact with void.");
				ft_exit(game, 0);
			}
			if ((game->map[i][j] == 'N' || game->map[i][j] == 'E' ||
			game->map[i][j] == 'W' || game->map[i][j] == 'S')
			&& (game->map[i - 1][j] == ' '
			|| game->map[i + 1][j] == ' '))
			{
				ft_putstr("Error\nMany spawn or in contact with space.");
				ft_exit(game, 0);
			}
		}
		j = -1;
	}
}
