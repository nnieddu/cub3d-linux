/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 15:34:56 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/30 13:33:01 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_check_0_out(t_cub3d *game, int i, int j)
{
	while (game->map[++i])
	{
		while (game->map[i][++j] && i != game->maplinecount)
		{
			if (game->map[i][j] == '0' && (ft_strlen(game->map[i - 1]) - 1 < j
			|| ft_strlen(game->map[i + 1]) - 1 < j))
			{
				ft_putstr("Error\nA 0 is in contact with void.");
				ft_exit(game, 0);
			}
			if (game->map[i][j] == '0' && (game->map[i - 1][j] == ' '
			|| game->map[i + 1][j] == ' '))
			{
				ft_putstr("Error\nA 0 is in contact with space.");
				ft_exit(game, 0);
			}
		}
		j = -1;
	}
}

int			ft_check_is_empty_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (i == ft_strlen(line))
		return (0);
	return (1);
}

int			ft_check_is_map_line(t_cub3d *game, char *line)
{
	if (game->arg_count == 8 && game->skip == 1)
	{
		if (ft_check_is_empty_line(line) == 0 && game->maplinecount == 0)
			return (0);
		return (1);
	}
	return (0);
}

void		ft_count_map_args(t_cub3d *game, char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] == 'R' || (line[i] == 'N' && line[i + 1] == 'O') ||
		(line[i] == 'S' && line[i + 1] == 'O') || (line[i] == 'W' &&
		line[i + 1] == 'E') || (line[i] == 'E' && line[i + 1] == 'A')
		|| (line[i] == 'S' && line[i + 1] != '1' && line[i + 1] != '0')
		|| line[i] == 'F' || line[i] == 'C')
			game->arg_count++;
		i++;
	}
	if (game->arg_count > 8)
	{
		ft_putstr("Error\nToo much arguments in the map\n");
		ft_exit(game, 0);
	}
	ft_check_map_arg(game, line, 0);
}

void		ft_check_map_arg(t_cub3d *game, char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] == 'R')
			game->arg_r++;
		if (game->arg_r == 1)
			if (((((line[i] < 48 || line[i] > 57) && line[i] != 32 &&
				line[i] != 'R') || game->arg_r > 2)))
			{
				ft_putstr("Error\nMultiple arg R or bad format.");
				ft_exit(game, 0);
			}
		i++;
	}
	if (game->arg_r == 1)
	{
		game->arg_r++;
		ft_catch_res(game, line, 0);
	}
	ft_texture_path(game, line, 0);
	ft_colors(game, line, -1, 1);
	if (game->verif_f > 1 || game->verif_c > 1)
	{
		ft_putstr("Error\nToo many argument F or C\n");
		ft_exit(game, 0);
	}
}
