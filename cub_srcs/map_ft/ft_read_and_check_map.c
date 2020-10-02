/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_check_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 11:50:46 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/30 14:08:20 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_check_map_closed_right(t_cub3d *game, int i, int j, char c)
{
	if (game->map[i])
		j = ft_strlen(game->map[i]) - 1;
	while (game->map[i])
	{
		while (game->map[i][j] != '0' && j != 0)
		{
			ft_is_out_of_map(game, i, j);
			if (game->map[i][j] == ' ')
				game->map[i][j] = c;
			j--;
		}
		if ((game->map[i][j + 1] != '1' && game->map[i][j + 1] != 'N'
		&& game->map[i][j + 1] != 'E' && game->map[i][j + 1] != 'W'
		&& game->map[i][j + 1] != 'S' && game->map[i][j + 1] != '2') && j != 0)
		{
			ft_putstr("Error\nBad character or hole on a line ");
			ft_putstr("(no new line allowed between map char).");
			ft_exit(game, 0);
		}
		i++;
		if (game->map[i])
			j = ft_strlen(game->map[i]) - 1;
	}
}

void		ft_check_map_closed_left(t_cub3d *game, int i, int j, char c)
{
	while (game->map[i])
	{
		while (game->map[i][j] != '0' && game->map[i][j] != '\0')
		{
			ft_is_out_of_map(game, i, j);
			if (game->map[i][j] == ' ')
				game->map[i][j] = c;
			j++;
		}
		if ((game->map[i][j - 1] != '1' && game->map[i][j - 1] != 'N'
		&& game->map[i][j - 1] != 'E' && game->map[i][j - 1] != 'W'
		&& game->map[i][j - 1] != 'S' && game->map[i][j - 1] != '2')
		&& j != ft_strlen(game->map[i]))
		{
			ft_putstr("Error\nBad character or hole on a line ");
			ft_putstr("(no new line allowed between map char).");
			ft_exit(game, 0);
		}
		i++;
		j = 0;
	}
	ft_check_map_closed_right(game, 0, 0, c);
}

void		ft_check_new_line(t_cub3d *game)
{
	int		i;

	i = ft_strlen(game->tmp_map);
	while (game->tmp_map[i] != '1')
		i--;
	while (i != 0)
	{
		if (game->tmp_map[i] == '\n' && game->tmp_map[i - 1] == '\n')
		{
			game->tmp_map[i] = '0';
			game->maplinecount--;
		}
		i--;
	}
}

void		ft_read_map(t_cub3d *game, int ret, char *line)
{
	while ((ret = get_next_line(game->fd, &line) > 0))
	{
		if (ft_check_is_empty_line(line) == 1)
			ft_count_map_args(game, line, 0);
		if (ft_check_is_map_line(game, line) == 1)
		{
			if (!(game->tmp_map = ft_strjoin(game->tmp_map, line)))
				ft_exit(game, 1);
			if (!(game->tmp_map = ft_strjoin(game->tmp_map, "\n")))
				ft_exit(game, 1);
			game->maplinecount++;
		}
		if (game->arg_count == 8 && game->skip == 0)
			game->skip++;
		ft_memdel((void*)&line);
	}
	if (ft_check_is_map_line(game, line) == 1)
	{
		if (!(game->tmp_map = ft_strjoin(game->tmp_map, line)))
			ft_exit(game, 1);
		if (!(game->tmp_map = ft_strjoin(game->tmp_map, "\n")))
			ft_exit(game, 1);
	}
	ft_memdel((void*)&line);
	close(game->fd);
}

void		ft_map(t_cub3d *game, int ret, char *line)
{
	if ((game->fd = open(game->map_path, O_RDONLY)) == -1)
	{
		ft_putstr("Error\nNo map found.\n");
		ft_exit(game, 0);
	}
	if (!(game->tmp_map = ft_strdup("")))
		ft_exit(game, 1);
	ft_read_map(game, ret, line);
	if (ft_is_map_ok(game, 0, 0, 0) != 0)
	{
		ft_putstr("Error\nNo tab allowed.\n");
		ft_exit(game, 0);
	}
	ft_check_new_line(game);
	if (!(game->map = ft_split(game->tmp_map, '\n')))
		ft_exit(game, 1);
	ft_check_0_out(game, 0, -1);
	ft_spawn_is_closed(game, 0, -1);
	ft_check_map_closed_left(game, 0, 0, ' ');
	ft_check_map_error(game, -1, 0);
}
