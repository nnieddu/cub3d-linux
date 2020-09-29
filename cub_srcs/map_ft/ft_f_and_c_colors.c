/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_and_c_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 15:25:51 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/29 16:16:26 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_init_colors(t_cub3d *game, t_color color, char *line, int x)
{
	color.argb[0] = ft_atoi(game->tab_color[2]);
	color.argb[1] = ft_atoi(game->tab_color[1]);
	color.argb[2] = ft_atoi(game->tab_color[0]);
	if (line[x] == 'F')
	{
		game->color_floor = color.color;
		game->verif_f++;
	}
	if (line[x] == 'C')
	{
		game->color_ceiling = color.color;
		game->verif_c++;
	}
}

void		ft_error_colors(t_cub3d *game, int i, int j)
{
	if (game->tab_color[0] == NULL || game->tab_color[1] == NULL ||
		game->tab_color[2] == NULL)
	{
		ft_putstr("Error\nArgument F or C have a bad format\n");
		ft_exit(game, 0);
	}
	if (0 > ft_atoi(game->tab_color[0]) || ft_atoi(game->tab_color[0]) > 255
			|| 0 > ft_atoi(game->tab_color[1]) || ft_atoi(game->tab_color[1])
				> 255 || 0 > ft_atoi(game->tab_color[2]) ||
					ft_atoi(game->tab_color[2]) > 255)
	{
		ft_putstr("Error\nColor error, 0 to 255 by color.\n");
		ft_exit(game, 0);
	}
	while (++i != 3)
	{
		j = 0;
		while (game->tab_color[i][j] != '\0' && game->tab_color[i][j] != ' ')
			j++;
		if (j > 3)
		{
			ft_putstr("Error\nColor error.\n");
			ft_exit(game, 0);
		}
	}
}

void		ft_check_path_colors(t_cub3d *game, char *line, int i, int j)
{
	if (!(game->tab_color = ft_split(&line[j], ',')))
		ft_exit(game, 1);
	while (i < 3)
	{
		if (game->tab_color[i][j] > 48 && game->tab_color[i][j] < 57)
		{
			while (game->tab_color[i][j] > 48 && game->tab_color[0][j] < 57)
				j++;
			game->check_color++;
		}
		if (game->tab_color[i][j] == '\0')
		{
			i++;
			j = 0;
			if (game->check_color > 1)
			{
				ft_putstr("Error\nArgument F or C have a bad format\n");
				ft_exit(game, 0);
			}
			game->check_color = 0;
		}
		j++;
	}
}

void		ft_check_comma(t_cub3d *game, char *line, int j, int x)
{
	int comma;

	comma = 0;
	x++;
	while (line[j] != '\0')
	{
		while (line[x] != '\0')
		{
			if ((line[x] < 48 || line[x] > 57) && line[x] != ','
				&& line[x] != ' ')
			{
				ft_putstr("Error\nArgument F or C have a bad format.\n");
				ft_exit(game, 0);
			}
			x++;
		}
		if (line[j] == ',')
			comma++;
		j++;
	}
	if (comma != 2)
	{
		ft_putstr("Error\nArgument F or C have a bad format.\n");
		ft_exit(game, 0);
	}
}

void		ft_colors(t_cub3d *game, char *line, int i, int j)
{
	t_color	color;
	int		x;

	x = 0;
	color.argb[2] = 0;
	while (line[x])
	{
		if (line[x] == 'F' || line[x] == 'C')
		{
			ft_check_comma(game, line, j, x);
			ft_check_path_colors(game, line, 0, x + 1);
			ft_error_colors(game, i, j);
			ft_init_colors(game, color, line, x);
			j = -1;
			while (game->tab_color[++j])
				ft_memdel((void*)&game->tab_color[j]);
			ft_memdel((void *)&(game->tab_color));
		}
		x++;
	}
	if (game->arg_r > 2)
	{
		ft_putstr("Error\nToo much R argument.\n");
		ft_exit(game, 0);
	}
}
