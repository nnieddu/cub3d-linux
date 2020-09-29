/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:16:07 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/29 13:02:39 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_is_out_of_map(t_cub3d *game, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'E' ||
		game->map[i][j] == 'W' || game->map[i][j] == 'S'
		|| game->map[i][j] == '2')
	{
		if (game->z != 0 && game->map[i][j + 1] != '1'
		&& game->map[i][j - 1] != '1')
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
		if (game->z == 0 && (game->map[i][j + 1] != '1' ||
		game->map[i][j - 1] != '1' ||
		game->map[i + 1][j] != '1' ||
		game->map[i - 1][j] != '1'))
		{
			ft_putstr("Error\nMap error, bad char in out or out of the map.");
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

void		ft_check_empty_line_next(t_cub3d *game, int i, int j, int s)
{
	while (game->map[++i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == ' ')
				s++;
			j++;
		}
		if (s == ft_strlen(game->map[i]))
		{
			ft_putstr("Error\nNew or empty line in the map spotted.1");
			ft_exit(game, 0);
		}
		j = 0;
		s = 0;
	}
}

void		ft_check_empty_line(t_cub3d *game, int i, int j, int s)
{
	i = game->maplinecount;
	j = ft_strlen(game->map[i]);
	while (game->map[i][j] != '1')
	{
		if (game->map[i][j] == ' ')
			game->map[i][j] = '1';
		if (j == 0)
		{
			i--;
			j = ft_strlen(game->map[i]);
		}
		j--;
	}
	ft_check_empty_line_next(game, -1, 0, s);
	i = 0;
	while (game->map[1][i] != '\0')
	{
		if (game->map[1][i] == '0' && i > ft_strlen(game->map[0]) - 1)
		{
			ft_putstr("Error\nThere's a hole in the first line.");
			ft_exit(game, 0);
		}
		i++;
	}
}

void		ft_first_and_last_check(t_cub3d *game, int i)
{
	while (game->map[0][i] != '\0')
	{
		if (game->map[0][i] == '0')
		{
			ft_putstr("Error\nThere's a hole or 0 out in the first line.");
			ft_exit(game, 0);
		}
		i++;
	}
	i = 0;
	while (game->map[game->maplinecount][i] != '\0')
	{
		if (game->map[game->maplinecount][i] == '0')
		{
			ft_putstr("Error\nThere's a hole or 0 out in the last linee.");
			ft_exit(game, 0);
		}
		i++;
	}
}
